#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include <woosh_ros_msgs/action/step_control.hpp>
#include <mutex>
#include <atomic>
#include <cmath>

using StepControl = woosh_ros_msgs::action::StepControl;
using GoalHandleStepControl = rclcpp_action::ClientGoalHandle<StepControl>;

class JoystickStepControlNode : public rclcpp::Node
{
public:
    JoystickStepControlNode()
        : Node("joystick_step_control_node"),
          linear_input_(0.0),
          angular_input_(0.0),
          was_moving_(false)
    {
        this->declare_parameter<double>("max_linear_speed", 0.5);
        this->declare_parameter<double>("max_angular_speed", 0.8);
        this->declare_parameter<double>("joystick_max", 10.0);
        this->declare_parameter<double>("deadzone", 1.0);
        this->declare_parameter<double>("control_rate", 10.0);
        this->declare_parameter<double>("step_distance", 0.1);
        this->declare_parameter<double>("step_rotation", 0.15);
        this->declare_parameter<double>("input_timeout", 0.4);  // INCREASED from 0.15
        this->declare_parameter<std::string>("joystick_topic", "/joystick_input");
        this->declare_parameter<std::string>("action_server", "/woosh_robot/ros/StepControl");

        max_linear_speed_ = this->get_parameter("max_linear_speed").as_double();
        max_angular_speed_ = this->get_parameter("max_angular_speed").as_double();
        joystick_max_ = this->get_parameter("joystick_max").as_double();
        deadzone_ = this->get_parameter("deadzone").as_double();
        control_rate_ = this->get_parameter("control_rate").as_double();
        step_distance_ = this->get_parameter("step_distance").as_double();
        step_rotation_ = this->get_parameter("step_rotation").as_double();
        input_timeout_ = this->get_parameter("input_timeout").as_double();
        std::string joystick_topic = this->get_parameter("joystick_topic").as_string();
        std::string action_server = this->get_parameter("action_server").as_string();

        action_client_ = rclcpp_action::create_client<StepControl>(this, action_server);

        RCLCPP_INFO(this->get_logger(), "Waiting for action server '%s'...", action_server.c_str());
        if (!action_client_->wait_for_action_server(std::chrono::seconds(20))) {
            RCLCPP_ERROR(this->get_logger(), "Action server not available!");
            rclcpp::shutdown();
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Connected!");

        last_input_time_ = this->now();

        joystick_sub_ = this->create_subscription<geometry_msgs::msg::Vector3>(
            joystick_topic, 10,
            std::bind(&JoystickStepControlNode::joystick_callback, this, std::placeholders::_1));

        double period_ms = 1000.0 / control_rate_;
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(static_cast<int>(period_ms)),
            std::bind(&JoystickStepControlNode::control_loop, this));

        RCLCPP_INFO(this->get_logger(), "=== Joystick Step Control ===");
        RCLCPP_INFO(this->get_logger(), "  Max speed: %.2f m/s, %.2f rad/s", max_linear_speed_, max_angular_speed_);
        RCLCPP_INFO(this->get_logger(), "  Step: %.2fm / %.2frad", step_distance_, step_rotation_);
        RCLCPP_INFO(this->get_logger(), "  Timeout: %.2fs", input_timeout_);
    }

private:
    void joystick_callback(const geometry_msgs::msg::Vector3::SharedPtr msg)
    {
        std::lock_guard<std::mutex> lock(input_mutex_);
        linear_input_ = msg->x;
        angular_input_ = msg->y;
        last_input_time_ = this->now();
    }

    double apply_deadzone(double value, double max_val)
    {
        if (std::abs(value) < deadzone_) return 0.0;
        double sign = (value > 0) ? 1.0 : -1.0;
        double scaled = (std::abs(value) - deadzone_) / (max_val - deadzone_);
        return sign * std::min(std::max(scaled, 0.0), 1.0);
    }

    void control_loop()
    {
        double linear_cmd, angular_cmd;
        
        {
            std::lock_guard<std::mutex> lock(input_mutex_);
            auto dt = (this->now() - last_input_time_).seconds();
            if (dt > input_timeout_) {
                linear_cmd = 0.0;
                angular_cmd = 0.0;
            } else {
                linear_cmd = apply_deadzone(linear_input_, joystick_max_);
                angular_cmd = apply_deadzone(angular_input_, joystick_max_);
            }
        }

        bool has_input = (std::abs(linear_cmd) > 0.01 || std::abs(angular_cmd) > 0.01);

        if (has_input) {
            send_move_step(linear_cmd, angular_cmd);
            was_moving_ = true;
        } else if (was_moving_) {
            send_stop();
            was_moving_ = false;
        }
    }

    void send_move_step(double linear_cmd, double angular_cmd)
    {
        auto goal = StepControl::Goal();
        goal.arg.action.value = 1;

        woosh_ros_msgs::msg::StepControlStep step;
        
        double lin_dist = linear_cmd * step_distance_;
        double ang_dist = angular_cmd * step_rotation_;
        double lin_speed = std::abs(linear_cmd) * max_linear_speed_;
        double ang_speed = std::abs(angular_cmd) * max_angular_speed_;
        
        bool has_lin = std::abs(linear_cmd) > 0.01;
        bool has_ang = std::abs(angular_cmd) > 0.01;

        if (has_lin && !has_ang) {
            step.mode.value = 1;
            step.value = lin_dist;
            step.speed = lin_speed;
            step.angle = 0.0;
        } else if (!has_lin && has_ang) {
            step.mode.value = 2;
            step.value = ang_dist;
            step.speed = ang_speed;
            step.angle = 0.0;
        } else {
            step.mode.value = 1;
            step.value = lin_dist;
            step.speed = lin_speed;
            step.angle = ang_dist;
        }

        goal.arg.steps.push_back(step);
        
        auto opts = rclcpp_action::Client<StepControl>::SendGoalOptions();
        opts.goal_response_callback = 
            [this](GoalHandleStepControl::SharedPtr goal_handle) {
                current_goal_handle_ = goal_handle;
            };
        action_client_->async_send_goal(goal, opts);
        
        RCLCPP_INFO(this->get_logger(), "MOVE: mode=%d val=%.3f spd=%.2f",
            step.mode.value, step.value, step.speed);
    }

    void send_stop()
    {
        RCLCPP_INFO(this->get_logger(), ">>> STOP <<<");
        
        {
            auto goal = StepControl::Goal();
            goal.arg.action.value = 0;
            action_client_->async_send_goal(goal);
        }
        
        {
            auto goal = StepControl::Goal();
            goal.arg.action.value = 1;
            woosh_ros_msgs::msg::StepControlStep step;
            step.mode.value = 1;
            step.value = 0.0;
            step.speed = 0.0;
            step.angle = 0.0;
            goal.arg.steps.push_back(step);
            action_client_->async_send_goal(goal);
        }
        
        if (current_goal_handle_) {
            action_client_->async_cancel_goal(current_goal_handle_);
            current_goal_handle_ = nullptr;
        }
    }

    rclcpp_action::Client<StepControl>::SharedPtr action_client_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr joystick_sub_;
    rclcpp::TimerBase::SharedPtr control_timer_;
    GoalHandleStepControl::SharedPtr current_goal_handle_;

    double max_linear_speed_, max_angular_speed_;
    double joystick_max_, deadzone_;
    double control_rate_, step_distance_, step_rotation_, input_timeout_;

    std::mutex input_mutex_;
    double linear_input_, angular_input_;
    rclcpp::Time last_input_time_;
    
    std::atomic<bool> was_moving_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<JoystickStepControlNode>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}