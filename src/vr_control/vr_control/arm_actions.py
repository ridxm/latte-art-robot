
import os
import sys
import time 

# module_path = "/home/rm/RM_API2/Demo/RMDemo_Python/RMDemo_Gripper/src"
# sys.path.append(module_path)

from Robotic_Arm.rm_robot_interface import *

class ArmActions:
    left_arm = RoboticArm(rm_thread_mode_e.RM_TRIPLE_MODE_E)
    right_arm = RoboticArm(rm_thread_mode_e.RM_TRIPLE_MODE_E)

    handle_left = left_arm.rm_create_robot_arm("169.254.128.18", 8080)
    handle_right = right_arm.rm_create_robot_arm("169.254.128.19", 8080)

    print("Left : ", handle_left.id)
    print("Right: ", handle_right.id)


    # print(left_arm.rm_set_lift_height(20, 400, 1))

    print(left_arm.rm_set_lift_speed(10))
    time.sleep(3)
    print(left_arm.rm_set_lift_speed(0))

    def lift_up(self):
        self.left_arm.rm_set_lift_speed(10)
        print("MF I Moving up")
        
    def lift_down(self):
        self.left_arm.rm_set_lift_speed(-10)
        print("MF I Moving down")

    def lift_stop(self):
        self.left_arm.rm_set_lift_speed(0)
        print("MF I Moving stop")



