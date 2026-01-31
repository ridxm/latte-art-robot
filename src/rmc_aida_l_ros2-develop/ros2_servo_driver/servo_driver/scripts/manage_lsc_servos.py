#!/usr/bin/env python3
import serial
import time
import sys

def open_serial(port):
    try:
        ser = serial.Serial(port, 9600, timeout=0.1)
        print(f"[INFO] Opened {port}")
        return ser
    except Exception as e:
        print(f"[ERROR] Failed to open {port}: {e}")
        return None

def read_lsc_position(ser, servo_id):
    """
    Read servo position using LSC Protocol Cmd 21 (0x15).
    Packet: 55 55 Len(03) Cmd(15) Count(01) ID
    Wait. `servo_driver_node` READS response. But how does it REQUEST?
    Actually, `servo_driver_node` doesn't seem to REQUEST positions?
    It has `sub_servo_get_angle_` which calls `callback_servo_get_angle`.
    `callback_servo_get_angle` writes:
    55 55 04 15 01 ID (6 bytes total?)
    s_buffer[2] = 0x04 (Len)
    s_buffer[3] = 0x15 (Cmd)
    s_buffer[4] = 0x01 (Count?)
    s_buffer[5] = msg->servo_id
    """
    # Request Packet
    # 55 55 04 15 01 ID
    cmd_packet = [0x55, 0x55, 0x04, 0x15, 0x01, servo_id]
    
    print(f"[READ] Sending Req for ID {servo_id}: {[hex(x) for x in cmd_packet]}")
    ser.reset_input_buffer()
    ser.write(bytearray(cmd_packet))
    time.sleep(0.05)
    
    # Read Response
    # Expect: 55 55 Len Cmd Count ID PosL PosH
    response = ser.read(100)
    if not response:
        print(f"[READ] No response from ID {servo_id}")
        return None
        
    print(f"[READ] Response: {[hex(x) for x in response]}")
    # Parse if possible
    # Look for 55 55
    res_bytes = list(response)
    for i in range(len(res_bytes)-1):
        if res_bytes[i] == 0x55 and res_bytes[i+1] == 0x55:
            # Found header
            try:
                # 55 55 Len Cmd Count ID PosL PosH
                # 0  1  2   3   4     5  6    7
                length = res_bytes[i+2]
                cmd = res_bytes[i+3]
                count = res_bytes[i+4]
                sid = res_bytes[i+5]
                pos_l = res_bytes[i+6]
                pos_h = res_bytes[i+7]
                angle = (pos_h << 8) | pos_l
                print(f"[READ] ID: {sid}, Angle: {angle}")
                return angle
            except IndexError:
                pass
    return None

def set_lsc_limit(ser, servo_id, min_val, max_val):
    """
    Attempt to set limit using LSC-formatted packet.
    Packet: 55 55 Len(0A) Cmd(14) Count(01) TimeL(00) TimeH(00) ID MinL MinH MaxL MaxH
    """
    length = 0x0A # 10 bytes payload? 
    # Payload: Cmd(1)+Count(1)+T(2)+ID(1)+Min(2)+Max(2) = 9 bytes?
    # If using Move-style convention (Len=PayloadBytes+1?), then 10.
    
    cmd = 0x14 # 20
    count = 0x01
    
    min_l = min_val & 0xFF
    min_h = (min_val >> 8) & 0xFF
    max_l = max_val & 0xFF
    max_h = (max_val >> 8) & 0xFF
    
    packet = [0x55, 0x55, length, cmd, count, 0x00, 0x00, servo_id, min_l, min_h, max_l, max_h]
    
    print(f"[WRITE LSC] Setting Limit ID {servo_id}: {[hex(x) for x in packet]}")
    ser.write(bytearray(packet))
    time.sleep(0.05)

def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyUSB0"
    ser = open_serial(port)
    if not ser: return
    
    ids = [1, 2]
    
    print("--- DIAGNOSTIC: READING POSITIONS ---")
    for i in ids:
        ang = read_lsc_position(ser, i)
        if ang is not None:
            print(f"Verified communication with ID {i}. Current Angle: {ang}")
            if ang <= 400 or ang >= 600:
                print(f"WARNING: Angle {ang} is near reported limit (400-600)!")
        else:
            print(f"FAILED to communicate with ID {i}")
            
    print("\n--- ACTION: WRITING LIMITS (0-1000) ---")
    print("Writing limits using LSC tunnel packet...")
    for i in ids:
        set_lsc_limit(ser, i, 0, 1000)
        
    print("Done. Please restart driver.")
    ser.close()

if __name__ == "__main__":
    main()
