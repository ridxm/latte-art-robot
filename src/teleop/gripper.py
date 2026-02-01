import socket
import time
# from pyDHgripper import AG95
import math
class Gripper:
    def __init__(self, ip = '169.254.128.18', port_no = 8080):


        # Create a socket and connect to the server
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((ip, port_no))
        print("First connection to the robotic arm", ip)

        time.sleep(0.5)


        point6_00 = '{"command":"set_tool_voltage","voltage_type":3}\r\n'
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.5)
        print("Setting tool voltage output to 24V")

        point6_00 = '{"command":"set_modbus_mode","port":1,"baudrate":115200,"timeout ":2}\r\n'
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.5)
        print("Configuring communication port to ModbusRTU mode")

        point6_00 = '{"command":"write_single_register","port":1,"address":256,"data":1, "device":1}\r\n'
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.5)
        print("Initialization Successful")
        # self.g = AG95(port='/dev/ttyUSB0')
        #point6_00 = '{"command":"write_single_register","port":1,"address":257,"data":30, "device":1}\r\n'
        #_ = send_cmd(self.client, cmd_6axis=point6_00)
        #time.sleep(2)

    def send_cmd(self, client, cmd_6axis):
        client.send(cmd_6axis.encode('utf-8'))
        # Optional: Receive a response from the server
        # _ = self.client.recv(1024).decode()
        return True

    # def read_position(self):
    #     # print("INITIALIZED")
    #     # print("Position:", self.g.read_pos())
    #     # print("State:", self.g.read_state())
    #     return self.g.read_pos()

    def open(self):
        point6_00 = '{"command":"write_single_register","port":1,"address":259,"data":1000, "device":1}\r\n'
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.001)

    def semi_open(self):
        point6_00 = '{"command":"write_single_register","port":1,"address":259,"data":500, "device":1}\r\n'
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.001)

    def close(self):
        point6_00 = '{"command":"write_single_register","port":1,"address":259,"data":0, "device":1}\r\n'
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.001)

    def pos_ctrl(self, pos):
        pos = int(min(max(pos * 1000, 0), 1000))
        point6_00 = (f'{{"command":"write_single_register","port":1,"address":259,"data":{pos}, "device":1}}\r\n')
        _ = self.send_cmd(self.client, cmd_6axis=point6_00)
        time.sleep(0.08)
    
    def command(self, command):
        if command == 0:
            self.close()
        elif command == 500:
            self.semi_open()
        elif command == 1000:
            self.open()

if __name__ == '__main__':
    gripper = Gripper()
    i = 0.0
    while True:
        pos = (math.cos(i / 100) + 1) / 2
        print(pos)
        gripper.pos_ctrl(pos)
        i +=1.0