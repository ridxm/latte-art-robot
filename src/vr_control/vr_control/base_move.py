#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32MultiArray
from woosh_robot_msgs.srv import Twist
from rm_ros_interfaces.msg import Gripperset, Liftspeed
import subprocess


class BaseMove(Node):

    

    def __init__(self):

        super().__init__("base_move")
        # self.joystick_subscriber = self.create_subscription(Joy, "joy", self.msgCallback, 10)
        self.vr_subscriber = self.create_subscription(Float32MultiArray, "calculated_delta", self.deltaCallback, 10)
        self.vr_actions = Float32MultiArray()

        # self.joystick_subscriber
        self.vr_subscriber
=
        self.lin_speed_scaling = 1.0
        self.ang_speed_scaling = 0.8
        self.linear = 0.0
        self.angular = 0.0
        self.down_button = 0
        self.up_button = 0
        self.left_gripper_val = 1.0
        self.right_gripper_val = 1.0
        self.last_right_gripper_val = None
        self.last_left_gripper_val = None
        self.lift_up = 0
        self.lift_down = 0
        self.lift_move_speed = 10
        self.timer = self.create_timer(1.0/30,self.drive_func)
        self.gripper_timer = self.create_timer(1.0/5, self.gripper_func)  
        self.base_client = self.create_client(Twist, "woosh_robot/robot/Twist")
        self.left_gripper_pub = self.create_publisher(Gripperset, "/left_arm_controller/rm_driver/set_gripper_position_cmd", 10)
        self.right_gripper_pub = self.create_publisher(Gripperset, "/right_arm_controller/rm_driver/set_gripper_position_cmd", 10)
        self.lift_pub = self.create_publisher(Liftspeed, "/left_arm_controller/rm_driver/set_lift_speed_cmd", 10)
        self.python39_path = "/usr/bin/python3.9"
        self.script_path = "/home/rm/RM_API2/Demo/RMDemo_Python/RMDemo_Gripper/src/core/gripper_client.py"
        # subprocess.run([self.python39_path, self.script_path])
        self.subprocess_queue = []  # Track subprocesses
        self.last_gripper_update_time = 0
        self.right_state = Gripperset()
        self.left_state = Gripperset()


    # def msgCallback(self, msg):
        
    #     self.linear = msg.axes[1] # Forward-backward
    #     self.angular = msg.axes[3] # SidewaysLeft-SidewaysRight
    #     self.left_gripper_val = msg.axes[2] # GripperLeft
    #     self.right_gripper_val = msg.axes[5] # gripper Right
    #     self.lift_up = msg.buttons[0]  # Lift up button A
    #     self.lift_down = msg.buttons[1] # Lift down buton B

    #     #Lift
    #     self.get_logger().info("Buttons: %s" %msg.buttons)



    def deltaCallback(self, msg):
        # self.vr_actions = msg
        # [ 0   1  2    3  4    5  6  7  8  9   10      11    12    13      14       15         16      17     18  19  20  21  22  23  24  25]
        # [XL, YL, ZL, XR, YR, ZR, A, B, X, Y, TrigL, TrigR, GripL, GripR, ThumbLX, ThumbLY, ThumbRX, ThumbRY, xL, yL, zL, wL, xR, yR, zR, wR]
        #  0   1  2   3   4    5   6   7  8    9  10  11 12  13  14 15 16 17   18     19     20     21      22      23       24         25   
        # XL, YL, ZL ,xL, yL, zL, wL, XR, YR, ZR, xR, yR, zR, wR, A, B, X, Y, TrigL, TrigR, GripL, GripR, ThumbLX, ThumbLY, ThumbRX, ThumbRY]

        self.linear = msg.data[23] / 100 # Forward-backward
        self.angular = -(msg.data[24] / 100) # SidewaysLeft-SidewaysRight
        self.left_gripper_val = 1000 - (msg.data[18] * 999) // 10# GripperLeft
        self.right_gripper_val = 1000 - (msg.data[19] * 999) // 10 # gripper Right
        self.lift_up = msg.data[14]  # Lift up button A
        self.lift_down = msg.data[15] # Lift down buton B
        

    def drive_func(self):
        self.get_logger().info("Linear: %s" %self.linear)
        self.get_logger().info("Angular: %s" % self.angular)
        
        self.req_ = Twist.Request()
        self.req_.arg.linear = self.linear * self.lin_speed_scaling
        self.req_.arg.angular = self.angular * self.ang_speed_scaling
        self.future_ = self.base_client.call_async(self.req_)
        self.future_.add_done_callback(self.move_callback)

        

    def gripper_func(self):
        self.left_state.position = int(self.left_gripper_val)
        self.left_state.block = False
        self.left_state.timeout = 0
        #for inspire gripper
        

        # if self.left_gripper_val != self.last_left_gripper_val and abs(self.left_gripper_val) == 1:
        #     self.last_left_gripper_val = self.left_gripper_val
        #     leftproc = subprocess.Popen([self.python39_path, self.script_path, "left", str(self.left_gripper_val)], 
        #                        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        #     self.subprocess_queue.append(leftproc)
      

        
        self.right_state.position = int(self.right_gripper_val)
        self.right_state.block = False
        self.right_state.timeout = 0
        self.left_gripper_pub.publish(self.left_state)
        self.right_gripper_pub.publish(self.right_state)
        #for jodell gripper
        # subprocess.run([self.python39_path, self.script_path, str(self.right_gripper_val)])
        # self.cleanup_subprocesses()
        # if self.right_gripper_val != self.last_right_gripper_val and abs(self.right_gripper_val) == 1:
        #     self.last_right_gripper_val = self.right_gripper_val
        #     rightproc = subprocess.Popen([self.python39_path, self.script_path, "right", str(self.right_gripper_val)], 
        #                  stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        #     self.subprocess_queue.append(rightproc)

        self.lift_state = Liftspeed()
        if not self.lift_up and not self.lift_down:
            self.lift_state.speed = 0
        elif self.lift_down and not self.lift_up:
            self.lift_state.speed = -self.lift_move_speed
        elif self.lift_up and not self.lift_down:
            self.lift_state.speed = self.lift_move_speed
        self.lift_pub.publish(self.lift_state)

        # self.cleanup_subprocesses()
        

        # self.subprocess_queue.append(proc)


    def move_callback(self, future):
        # if future.result().ok:
        try:
            result = future.result()
            if result:
                pass  # Success - no need to log every time
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")    
        # self.get_logger().info("bc i am moving")
    # def cleanup_subprocesses(self):
    #     """Remove finished subprocesses"""
    #     self.subprocess_queue = [p for p in self.subprocess_queue if p.poll() is None]


def main():
    rclpy.init()

    base_move = BaseMove()
    rclpy.spin(base_move)
    
    base_move.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()