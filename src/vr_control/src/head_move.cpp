#include "rclcpp/rclcpp.hpp"
#include "servo_interfaces/msg/servo_move.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include <cmath>
#include <algorithm>
#include <chrono>
#include <deque>
#include <numeric>

struct HeadPosition {
    float horizontal;
    float vertical;
};

HeadPosition quat_to_head(float x, float y, float z, float w) {
    /*
     * Ultra-optimized quaternion to robot head conversion
     * Coordinate frame: X=Forward, Y=Left, Z=Up
     * Forward direction: +X axis
     * 90° rotation gives full 0-1000 range
     */
    
    // Normalize quaternion
    float norm = std::sqrt(x*x + y*y + z*z + w*w);
    if (norm > 0.0f) {
        x /= norm; y /= norm; z /= norm; w /= norm;
    }
    
    // Pre-compute squared terms
    const float qx2 = x * x;
    const float qy2 = y * y;
    const float qz2 = z * z;
    
    // Pre-compute products
    const float qxqy = x * y;
    const float qxqz = x * z;
    const float qzqw = z * w;
    const float qyqw = y * w;
    
    // Rotate forward vector [1, 0, 0] by quaternion
    const float x_rot = 1.0f - 2.0f * (qy2 + qz2);
    const float y_rot = 2.0f * (qxqy + qzqw);
    const float z_rot = 2.0f * (qxqz - qyqw);
    
    // Calculate angles
    const float yaw = std::atan2(-y_rot, x_rot);
    const float horizontal_dist = std::sqrt(x_rot * x_rot + y_rot * y_rot);
    const float pitch = std::atan2(z_rot, horizontal_dist);
    
    // Constants
    constexpr float PI_2 = 1.57079632679f;
    constexpr float SCALE = 318.309886184f;  // 1000/pi
    
    // Map to 0-1000 range with 90° total rotation giving full range
    // Scale by 2x so that ±45° (90° total) maps to 0-1000
    float head_horizontal = (-yaw * 2.0f + PI_2) * SCALE;
    float head_vertical = (pitch * 2.0f + PI_2) * SCALE;
    
    // Clamp to 0-1000
    head_horizontal = std::max(0.0f, std::min(1000.0f, head_horizontal));
    head_vertical = std::max(0.0f, std::min(1000.0f, head_vertical));
    
    return {head_horizontal, head_vertical};
}

class VRHeadControl : public rclcpp::Node
{
public:
  VRHeadControl() : Node("vr_head_control_node")
  {
    RCLCPP_INFO(this->get_logger(), "VR Head Control Node Started!");
    
    // Create publisher for servo commands
    publisher_ = this->create_publisher<servo_interfaces::msg::ServoMove>("/servo_control/move", 10);
    
    // Create subscriber for VR quaternion data
    subscription_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(
      "/calculated_delta",
      10,
      std::bind(&VRHeadControl::quaternion_callback, this, std::placeholders::_1)
    );
    
    // Create timer for 3 Hz publishing (333 ms)
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(250),
      std::bind(&VRHeadControl::publish_servo_commands, this)
    );
    
    RCLCPP_INFO(this->get_logger(), "Listening on /calculated_delta for VR quaternion data...");
  }

private:
  float latest_horizontal_ = 500.0f;
  float latest_vertical_ = 500.0f;
  bool data_received_ = false;
  float filtered_horizontal_ = 500.0f;
  float filtered_vertical_ = 500.0f;
  std::deque<float> horizontal_window_;
  std::deque<float> vertical_window_;
  int last_horizontal_cmd_ = 500;
  int last_vertical_cmd_ = 500;
  bool first_publish_ = true;

  // Smoothing parameters
  const float smoothing_alpha_ = 0.15f;    // 0 < alpha <= 1, lower is smoother
  const float deadband_ = 5.0f;            // Ignore tiny fluctuations (servo units)
  const size_t smoothing_window_size_ = 10;
  const int publish_deadband_ = 2;         // Minimum change (servo units) before publishing

  float apply_smoothing(float target, float current)
  {
    float delta = target - current;
    if (std::fabs(delta) < deadband_) {
      return current;
    }
    return current + smoothing_alpha_ * delta;
  }

  float update_window(std::deque<float>& window, float value)
  {
    window.push_back(value);
    if (window.size() > smoothing_window_size_) {
      window.pop_front();
    }
    float sum = std::accumulate(window.begin(), window.end(), 0.0f);
    return sum / static_cast<float>(window.size());
  }

  void quaternion_callback(const std_msgs::msg::Float32MultiArray::SharedPtr msg)
  {
    // Check if array has at least 4 elements
    if (msg->data.size() < 4) {
      RCLCPP_WARN(this->get_logger(), "Received array with less than 4 elements!");
      return;
    }
    
    // Extract last 4 elements (x, y, z, w)
    size_t size = msg->data.size();
    float x = msg->data[size - 4];
    float y = msg->data[size - 3];
    float z = msg->data[size - 2];
    float w = msg->data[size - 1];
    
    // Convert quaternion to head position
    HeadPosition pos = quat_to_head(x, y, z, w);
    
    // Apply windowed average to reduce noise
    float averaged_horizontal = update_window(horizontal_window_, pos.horizontal);
    float averaged_vertical = update_window(vertical_window_, pos.vertical);

    // Apply smoothing to reduce jitter
    filtered_horizontal_ = apply_smoothing(averaged_horizontal, filtered_horizontal_);
    filtered_vertical_ = apply_smoothing(averaged_vertical, filtered_vertical_);

    // Update latest values
    latest_horizontal_ = filtered_horizontal_;
    latest_vertical_ = filtered_vertical_;
    data_received_ = true;
    
    RCLCPP_DEBUG(this->get_logger(), "Quaternion: [%.3f, %.3f, %.3f, %.3f] -> H: %.1f, V: %.1f", 
                 x, y, z, w, pos.horizontal, pos.vertical);
  }

  void publish_servo_commands()
  {
    if (!data_received_) {
      RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000, 
                           "No VR data received yet...");
      return;
    }
    
    bool is_first_publish = first_publish_;

    // Calculate command angles with clamping and rounding
    float clamped_horizontal = std::max(0.0f, std::min(1000.0f, latest_horizontal_));
    float clamped_vertical = std::max(0.0f, std::min(1000.0f, latest_vertical_));
    int horiz_cmd = static_cast<int>(std::round(clamped_horizontal));
    int vert_cmd = static_cast<int>(std::round(clamped_vertical));

    if (is_first_publish || std::abs(horiz_cmd - last_horizontal_cmd_) >= publish_deadband_) {
      auto msg_horiz = servo_interfaces::msg::ServoMove();
      msg_horiz.servo_id = 2;
      msg_horiz.angle = horiz_cmd;
      RCLCPP_INFO(this->get_logger(), "Horizontal: servo_id=%d, angle=%d", 
                  msg_horiz.servo_id, msg_horiz.angle);
      publisher_->publish(msg_horiz);
      last_horizontal_cmd_ = horiz_cmd;
    }

    if (is_first_publish || std::abs(vert_cmd - last_vertical_cmd_) >= publish_deadband_) {
      auto msg_vert = servo_interfaces::msg::ServoMove();
      msg_vert.servo_id = 1;
      msg_vert.angle = vert_cmd;
      RCLCPP_INFO(this->get_logger(), "Vertical: servo_id=%d, angle=%d", 
                  msg_vert.servo_id, msg_vert.angle);
      publisher_->publish(msg_vert);
      last_vertical_cmd_ = vert_cmd;
    }

    first_publish_ = false;
  }

  rclcpp::Publisher<servo_interfaces::msg::ServoMove>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr subscription_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VRHeadControl>());
  rclcpp::shutdown();
  return 0;
}