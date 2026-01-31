#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
import subprocess
import firebase_admin
from firebase_admin import credentials, db
import numpy as np
from scipy.spatial.transform import Rotation as R
from pyquaternion import Quaternion
import socket
import json
import time
import os
import platform
import threading
from queue import Queue, Empty


class DeltaCalc(Node):
    
    def __init__(self):
        super().__init__("delta_calculation")
        UDP_IP = "0.0.0.0"
        UDP_PORT = 9999  
        
        # Setup socket with optimizations
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        # Increase buffer size for better performance
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 65536)
        self.sock.bind((UDP_IP, UDP_PORT))
        self.array_size = 30

        # Register this client as a receiver
        self.register_message = {
            "id": "qwe",
            "client_type": "receiver",
            "data": [],
            "type": "register"
        }
        self.sock.sendto(json.dumps(self.register_message).encode(), ("18.189.28.114", UDP_PORT))
        # self.sock.sendto(json.dumps(self.register_message).encode(), ("18.222.191.128", UDP_PORT))
        
        # Pre-allocate arrays for better performance
        self.prev = np.array([0] * self.array_size, dtype=np.float32)
        self.data = np.zeros(self.array_size, dtype=np.float32)
        self.delta = np.zeros(self.array_size, dtype=np.float32)
        self.delta_flat = [0.0] * self.array_size
        
        # Thread-safe data sharing
        self.latest_data = None
        self.data_lock = threading.Lock()
        self.new_data_available = False
        
        # Start UDP receiver in separate thread
        self.udp_thread = threading.Thread(target=self.udp_receiver_thread, daemon=True)
        self.udp_thread.start()
        
        # Publisher
        self.delta_pub = self.create_publisher(Float32MultiArray, "/calculated_delta", 10)
        
        # Timer for processing data
        self.timer = self.create_timer(1.0/70, self.fetch_data)

    def udp_receiver_thread(self):
        """Separate thread for UDP data reception to avoid blocking"""
        while True:
            try:
                incoming, addr = self.sock.recvfrom(2046)
                message = json.loads(incoming.decode())
                
                # Update latest data in thread-safe manner
                with self.data_lock:
                    self.latest_data = message['data']
                    self.new_data_available = True
                    
            except socket.error:
                time.sleep(0.001)  # Brief sleep on socket error
            except (json.JSONDecodeError, KeyError) as e:
                # Handle JSON decode errors or missing 'data' key
                continue
            except Exception as e:
                self.get_logger().error(f"UDP receiver error: {e}")

    def fetch_data(self):
        # Get latest data if available
        with self.data_lock:
            if not self.new_data_available or self.latest_data is None:
                return
            
            # Copy data and reset flag
            current_data = self.latest_data[:]
            self.new_data_available = False
        
        try:
            # Convert to numpy array (preserve original data type handling)
            self.data = np.array(current_data)
        except Exception as e:
            self.get_logger().error(f"[ERROR] Invalid data: {current_data} | Error: {e}")
            return

        # [ 0   1  2    3  4    5  6  7  8  9   10      11    12    13      14       15         16      17      18  19  20  21 22  23  24  25  26  27  28  29]
        # [XL, YL, ZL, XR, YR, ZR, A, B, X, Y, TrigL, TrigR, GripL, GripR, ThumbLX, ThumbLY, ThumbRX, ThumbRY, xL, yL, zL, wL, xR, yR, zR, wR, xH, yH, zH, wH]
        if self.data[0] != None:
            start_time = time.time()
            self.get_logger().info("data received")

            # Calculate delta using in-place operations for speed
            np.subtract(self.prev, self.data, out=self.delta)
            # self.get_logger().info(f"delta{self.delta} data {self.data} prev {self.prev}")
            np.copyto(self.prev, self.data)
            
            # Convert to list once (faster than repeated conversions)
            self.delta_flat = self.delta.tolist()
            
            # Pre-allocate message data
            axis_data = Float32MultiArray()
            axis_data.data = [0.0] * self.array_size
            
            # Copy data slice directly (preserve original logic)
            for offset, val in enumerate(self.data[6:18]):
                axis_data.data[14 + offset] = float(val)

            axis_data.data[26] = self.data[26]
            axis_data.data[27] = self.data[27]
            axis_data.data[28] = self.data[28]
            axis_data.data[29] = self.data[29]

            if self.data[13] == 10 or self.data[12] == 10:
                if self.data[13] == 10:
                    #right
                    axis_data.data[7] = -float(self.delta_flat[5]) * 30
                    axis_data.data[8] = float(self.delta_flat[3]) * 30
                    axis_data.data[9] = -float(self.delta_flat[4]) * 30
                    # axis_data.data[7] = float(result_r[0])
                    # axis_data.data[8] = float(result_r[1])
                    # axis_data.data[9] = float(result_r[2])
                    axis_data.data[10] = float(self.data[22])
                    axis_data.data[11] = float(self.data[23])
                    axis_data.data[12] = float(self.data[24])
                    axis_data.data[13] = float(self.data[25])
                    # axis_data.data[10] = q[0]
                    # axis_data.data[11] = q[1]
                    # axis_data.data[12] = q[2]
                    # axis_data.data[13] = q[3]
                    # self.delta_pub.publish(axis_data)

                if self.data[12] == 10:
                    #left
                    axis_data.data[0] = -float(self.delta_flat[2])* 30
                    axis_data.data[1] = float(self.delta_flat[0])* 30
                    axis_data.data[2] = -float(self.delta_flat[1])* 30
                    # axis_data.data[3] = float(q_l[0])
                    # axis_data.data[4] = -float(q_l[1])
                    # axis_data.data[5] = float(q_l[2])
                    # axis_data.data[6] = float(q_l[3])
                    axis_data.data[3] = float(self.data[18])
                    axis_data.data[4] = float(self.data[19])
                    axis_data.data[5] = float(self.data[20])
                    axis_data.data[6] = float(self.data[21])
                
                # axis_data.data[14:] = self.delta_flat[6:18]

                self.delta_pub.publish(axis_data)
                
            else:
                # axis_data.data = [0.0]* self.array_size
                # axis_data.data[14:] = self.delta_flat[6:18]
                self.delta_pub.publish(axis_data)
                
            current_time = time.time()
            self.get_logger().info(str(current_time - start_time))
        else:
            self.get_logger().info("data not received")


def main():
    rclpy.init()
    send_delta = DeltaCalc()
    rclpy.spin(send_delta)
    
    send_delta.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


# #!/usr/bin/env python3
# import rclpy
# from rclpy.node import Node
# from std_msgs.msg import Float32MultiArray
# import subprocess
# import firebase_admin
# from firebase_admin import credentials, db
# import numpy as np
# from scipy.spatial.transform import Rotation as R
# from pyquaternion import Quaternion
# import socket
# import json
# import time
# import os
# import platform


# class DeltaCalc(Node):

    

#     def __init__(self):

#         super().__init__("delta_calculation")
#         UDP_IP = "0.0.0.0"
#         UDP_PORT = 9999  
#         self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#         self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#         self.sock.bind((UDP_IP, UDP_PORT))

#         # Register this client as a receiver
#         self.register_message = {
#             "id": 1,
#             "client_type": "receiver",
#             "data": [],
#             "type": "register"
#         }
#         # self.sock.sendto(json.dumps(self.register_message).encode(), ("18.222.191.128", UDP_PORT))
#         self.timer = self.create_timer(1.0/70,self.fetch_data)
#         self.prev = np.array([0] * 26)
#         self.delta_pub = self.create_publisher(Float32MultiArray, "/calculated_delta", 10)
#         # subprocess.run([self.python39_path, self.script_path])
        


#     def fetch_data(self):
#         axis_data = Float32MultiArray()
#         incoming, addr = self.sock.recvfrom(2046)
        
#         try:
#             message = json.loads(incoming.decode())
#             # print(f"[LATEST DATA] {message['data']}")
#             self.data = np.array(message['data'])

#         except Exception as e:
#             # print(f"[ERROR] Invalid data: {data} | Error: {e}")
#             self.get_logger().error("[ERROR] Invalid data: {data} | Error: {e}")

        
#         # [ 0   1  2    3  4    5  6  7  8  9   10      11    12    13      14       15         16      17      18  19  20  21 22  23  24  25]
#         # [XL, YL, ZL, XR, YR, ZR, A, B, X, Y, TrigL, TrigR, GripL, GripR, ThumbLX, ThumbLY, ThumbRX, ThumbRY, xL, yL, zL, wL, xR, yR, zR, wR]
#         if self.data[0] != None:
#             start_time = time.time()
#             self.get_logger().info("data received")


#             self.delta = np.subtract(self.prev,self.data)
#             # self.get_logger().info(f"delta{self.delta} data {self.data} prev {self.prev}")
#             self.prev = self.data
#             self.delta_flat = list(self.delta.flatten())
#             axis_data.data = [0.0]* 26
#             for offset, val in enumerate(self.data[6:18]):
#                 axis_data.data[14 + offset] = float(val)

#             if self.data[13] == 10 or self.data[12] == 10:
#                 if self.data[13] == 10:
#                     #right
#                     axis_data.data[7] = -float(self.delta_flat[5]) * 30
#                     axis_data.data[8] = float(self.delta_flat[3]) * 30
#                     axis_data.data[9] = -float(self.delta_flat[4]) * 30
#                     # axis_data.data[7] = float(result_r[0])
#                     # axis_data.data[8] = float(result_r[1])
#                     # axis_data.data[9] = float(result_r[2])
#                     axis_data.data[10] = float(self.data[22])
#                     axis_data.data[11] = float(self.data[23])
#                     axis_data.data[12] = float(self.data[24])
#                     axis_data.data[13] = float(self.data[25])
#                     # axis_data.data[10] = q[0]
#                     # axis_data.data[11] = q[1]
#                     # axis_data.data[12] = q[2]
#                     # axis_data.data[13] = q[3]
#                     # self.delta_pub.publish(axis_data)

#                 if self.data[12] == 10:
#                     #left
#                     axis_data.data[0] = -float(self.delta_flat[2])* 30
#                     axis_data.data[1] = float(self.delta_flat[0])* 30
#                     axis_data.data[2] = -float(self.delta_flat[1])* 30
#                     # axis_data.data[3] = float(q_l[0])
#                     # axis_data.data[4] = -float(q_l[1])
#                     # axis_data.data[5] = float(q_l[2])
#                     # axis_data.data[6] = float(q_l[3])
#                     axis_data.data[3] = float(self.data[18])
#                     axis_data.data[4] = float(self.data[19])
#                     axis_data.data[5] = float(self.data[20])
#                     axis_data.data[6] = float(self.data[21])
                
#                 # axis_data.data[14:] = self.delta_flat[6:18]
#                 self.delta_pub.publish(axis_data)
                
#             else:
#                 # axis_data.data = [0.0]* 26
#                 # axis_data.data[14:] = self.delta_flat[6:18]
#                 self.delta_pub.publish(axis_data)
#             current_time = time.time()
#             self.get_logger().info(str(current_time - start_time))
#         else:
#             self.get_logger().info("data not received")

#                         # Rotation_matrix= np.array([
#             #     [-0.707106, 0.0, -0.707106],
#             #     [0.707106,  0.0, -0.707106],
#             #     [0.0,  -1.0, 0.0]
#             # ])
#             # # Rotation_matrix= np.array([
#             # #     [-1.0, 0.0, 0.0],
#             # #     [0.0,  0.0, -1.0],
#             # #     [0.0,  -1.0, 0.0]
#             # # ])

#             # Rotation_matrix_2 = np.array([
#             #     [1.0 ,0.0 ,0.0],
#             #     [0.0, 0.0, 1.0],
#             #     [0.0, -1.0, 0.0]
#             # ])

#             # Define the 3D vector
            
            
#             # v_r = np.array([self.delta_flat[3], self.delta_flat[4], self.delta_flat[5]])
#             # v_l = np.array([self.delta_flat[3], self.delta_flat[4], self.delta_flat[5]])
#             # # Matrix-vector multiplication
#             # result_l = Rotation_matrix @ v_l
#             # result_r = Rotation_matrix_2 @ v_r  # or np.dot(R, v)


#             # q_norm = np.array([self.data[22], self.data[23], self.data[24], self.data[25]])
#             # q_norm = q_norm / np.linalg.norm(q_norm)
#             # # q1 = R.from_quat([q_norm[0], q_norm[1], q_norm[2], q_norm[3]])
#             # q1 = R.from_quat([self.data[22],self.data[23] , self.data[24], self.data[25]]) # example orientation
#             # q2 = R.from_quat([self.data[18],self.data[19] , self.data[20], self.data[21]])
#             # # Convert rotation matrix to quaternion and create Rotation object
#             # qR_rot = R.from_matrix(Rotation_matrix_2)
#             # # qR_inv = qR_rot.inv()

#             # # Apply the transformation: q2 = qR * q1 * qR⁻¹
#             # q2_rot = qR_rot*q1
#             # q2_rot_l = qR_rot*q2

#             # # Output the result
#             # self.get_logger().info(f"wannabe_quaternion: {q2_rot}")
#             # q = q2_rot.as_quat()
#             # q_l = q2_rot_l.as_quat()
#             # self.get_logger().info(f"wannabe_quaternion2: {q}")  

#             # #reflect x     
#             # q_rh = [float(self.data[22]), float(self.data[24]),float(self.data[23]), float(self.data[25])]
#             # rot = R.from_quat([q_rh[1], q_rh[2], q_rh[3], q_rh[0]])
#             # M = q1.as_matrix()

#             # # Reflection matrix flipping X axis
#             # R_reflect = np.diag([1, -1, -1])

#             # # New rotation matrix in RH frame
#             # M_rh = R_reflect @ M 

#             # # Convert back; returns [x, y, z, w]
#             # q_xyzw = R.from_matrix(M_rh).as_quat()
#             # # Reorder to [w, x, y, z]
#             # qr_rh = np.array([q_xyzw[0], q_xyzw[1], q_xyzw[2], q_xyzw[3]])
            
#             # # q_inv_z = invert_yaw(np.array([self.data[22],self.data[24], self.data[23], self.data[25]]))
#             # q_norm = np.array([self.data[22], self.data[23], self.data[24], self.data[25]])
#             # q_norm = q_norm / np.linalg.norm(q_norm)    
#             # q_inv_z = invert_yaw(q_norm)

 

# # def invert_yaw(quat: np.ndarray) -> np.ndarray:
# #     """
# #     Invert the yaw (rotation about global Z) of a quaternion
# #     while preserving roll & pitch.

# #     Parameters
# #     ----------
# #     quat : array-like, shape (4,)
# #         Input quaternion in [x, y, z, w] order (SciPy convention).

# #     Returns
# #     -------
# #     q_new : ndarray, shape (4,)
# #         Output quaternion [x, y, z, w] with yaw negated.
# #     """
# #     # Ensure we have a float array
# #     q = np.asarray(quat, dtype=float)
# #     x, y, z, w = q

# #     # Compute cos(phi) and sin(phi) for the original yaw φ
# #     c = w*w + x*x - y*y - z*z
# #     s = 2*(w*z - x*y)

# #     # Build the "flip" quaternion for rotation by -2φ around Z: [0,0,-s,c]
# #     q_flip = np.array([0.0, 0.0, -s, c])
# #     q_flip /= np.linalg.norm(q_flip)

# #     # Compose: new = q_flip ∘ q
# #     r_flip = R.from_quat(q_flip)
# #     r_orig = R.from_quat(q)
# #     r_new  = r_flip * r_orig

# #     return r_new.as_quat()

# def main():
#     rclpy.init()

#     send_delta = DeltaCalc()
#     rclpy.spin(send_delta)
    
#     send_delta.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()
