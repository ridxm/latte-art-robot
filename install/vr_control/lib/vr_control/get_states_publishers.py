#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Empty
from rm_ros_interfaces.msg import Armstate, Liftstate

class GetStatesPublishers(Node):
    def __init__(self):
        super().__init__("get_states_publishers")
        
        self.joint_states_right = [0.0]*6
        self.joint_states_left = [0.0]*6
        self.lift_height = 0
        
        self.right_current_state_pub = self.create_publisher(Empty, "/right_arm_controller/rm_driver/get_current_arm_state_cmd", 10)
        self.left_current_state_pub = self.create_publisher(Empty, "/left_arm_controller/rm_driver/get_current_arm_state_cmd", 10)
        self.lift_state_pub = self.create_publisher(Empty, "/left_arm_controller/rm_driver/get_lift_state_cmd", 10)
        
        self.right_current_state_sub = self.create_subscription(Armstate, "/right_arm_controller/rm_driver/get_current_arm_state_result", self.right_arm_read, 10)
        self.left_current_state_sub = self.create_subscription(Armstate, "/left_arm_controller/rm_driver/get_current_arm_state_result", self.left_arm_read, 10)
        self.lift_state_sub = self.create_subscription(Liftstate,"/left_arm_controller/rm_driver/get_lift_state_result", self.lift_state_read, 10)
        
        self.frequency_ = 70
        self.get_logger().info("Publishing at %d Hz" % self.frequency_)
        
        self.timer_ = self.create_timer(1.0/self.frequency_, self.timerCallback)
    
    def timerCallback(self):
        msg = Empty()
        self.left_current_state_pub.publish(msg)
        self.right_current_state_pub.publish(msg)
        self.lift_state_pub.publish(msg)
        
        # Optional: Log the joint states if needed
        # joint_array = self.joint_states_left + self.joint_states_right + [self.lift_height]
        # formatted = ", ".join(["%.2f" % val for val in joint_array])
        # self.get_logger().info("Joint states: [%s]" % formatted)
    
    def right_arm_read(self, msg):
        self.joint_states_right = list(msg.joint)
    
    def left_arm_read(self, msg):
        self.joint_states_left = list(msg.joint)
    
    def lift_state_read(self, msg):
        self.lift_height = msg.height
        self.get_logger().info("Lift height: %d" % self.lift_height)

def main():
    rclpy.init()
    get_states_publishers = GetStatesPublishers()
    rclpy.spin(get_states_publishers)
    
    get_states_publishers.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


# #!/usr/bin/env python3
# import rclpy
# from rclpy.node import Node
# from std_msgs.msg import Empty
# from rm_ros_interfaces.msg import Armstate, Liftstate
# import firebase_admin
# from firebase_admin import credentials, db



# class GetStatesPublishers(Node):

#     def __init__(self):
#         super().__init__("get_states_publishers")
#         self.cred = credentials.Certificate("/home/rm/ros2_ws/src/vr_control/config/google-service2.json")
#         firebase_admin.initialize_app(self.cred, {
#             "databaseURL": "https://teleop-bot-default-rtdb.asia-southeast1.firebasedatabase.app/"
#         })
#         self.ref = db.reference("ArmValues")
#         self.joint_states_right = [0.0]*6
#         self.joint_states_left = [0.0]*6
#         self.lift_height = 0
#         self.right_current_state_pub = self.create_publisher(Empty, "/right_arm_controller/rm_driver/get_current_arm_state_cmd", 10)
#         self.left_current_state_pub = self.create_publisher(Empty, "/left_arm_controller/rm_driver/get_current_arm_state_cmd", 10)
#         self.lift_state_pub = self.create_publisher(Empty, "/left_arm_controller/rm_driver/get_lift_state_cmd", 10)
#         self.right_current_state_sub = self.create_subscription(Armstate, "/right_arm_controller/rm_driver/get_current_arm_state_result", self.right_arm_read, 10)
#         self.left_current_state_sub = self.create_subscription(Armstate, "/left_arm_controller/rm_driver/get_current_arm_state_result", self.left_arm_read, 10)
#         self.lift_state_sub = self.create_subscription(Liftstate,"/left_arm_controller/rm_driver/get_lift_state_result", self.lift_state_read, 10)
        
#         # self.msg = Empty()
#         self.frequency_ = 70
#         self.get_logger().info("Publishing at %d Hz" % self.frequency_)
        
#         self.timer_ = self.create_timer(1.0/self.frequency_, self.timerCallback)

#     def timerCallback(self):
#         msg = Empty()
#         self.left_current_state_pub.publish(msg)
#         self.right_current_state_pub.publish(msg)
#         self.lift_state_pub.publish(msg)

#         ref = db.reference('ArmValues')
#         # [LJ1, LJ2, LJ3, LJ4, LJ5, LJ6, RJ1, RJ2, RJ3, RJ4, RJ5, RJ6, lift_height]
#         joint_array = self.joint_states_left + self.joint_states_right + [self.lift_height]
#         ref.set(joint_array)
#         # formatted = ", ".join(["%.2f" % val for val in joint_array])
#         # self.get_logger().info("sending LR  [%s]" % formatted)



#     def right_arm_read(self, msg):
#         self.joint_states_right  = list(msg.joint)
#         # self.get_logger().info("RJ1 %f" % self.joint_states_right[0])

#     def left_arm_read(self, msg):
#         self.joint_states_left  = list(msg.joint)
#         # self.get_logger().info("LJ1 %f" % self.joint_states_left[0])

#     def lift_state_read(self, msg):
#         self.lift_height  = msg.height
#         self.get_logger().info("LJ1 %d" % self.lift_height)

# def main():
#     rclpy.init()

#     get_states_publishers = GetStatesPublishers()
#     rclpy.spin(get_states_publishers)
    
#     get_states_publishers.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()