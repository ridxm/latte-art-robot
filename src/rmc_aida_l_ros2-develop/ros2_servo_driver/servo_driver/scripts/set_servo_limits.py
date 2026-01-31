#!/usr/bin/env python3
import serial
import time
import sys

def checksum(data_bytes):
    """
    Calculate checksum for Lobot/Hiwonder packet.
    Checksum = ~(Sum(data_bytes)) & 0xFF
    """
    total = sum(data_bytes)
    return (~total) & 0xFF

def send_bus_servo_limit(ser, servo_id, min_val, max_val, len_convention=7):
    """
    Send Standard Bus Servo Limit Command (Cmd 20 / 0x14).
    Packet: 55 55 ID Len Cmd MinL MinH MaxL MaxH Checksum
    
    Arguments:
    len_convention: Some docs say Len=7, some say Len=ParamLen+2.
    We'll construct based on the requested length.
    """
    # Params: MinL, MinH, MaxL, MaxH (4 bytes)
    cmd = 20 # 0x14
    p1 = min_val & 0xFF
    p2 = (min_val >> 8) & 0xFF
    p3 = max_val & 0xFF
    p4 = (max_val >> 8) & 0xFF
    params = [p1, p2, p3, p4]
    
    # Structure: ID, Len, Cmd, Params... Checksum calculated on these.
    # If len_convention is 7 (from docs), it fits: Cmd(1)+Params(4)+Checksum(1)+ID(1) = 7? No.
    # Usually Len = Number of bytes FOLLOWING Len?
    # Or Len = ParamCount + 2? (4+2=6).
    
    # We will compute checksum on ID + Len + Cmd + Params.
    # But wait, usually standard is Checksum = ~(ID + Len + Cmd + Params).
    # So we construct the 'body' first.
    
    packet_body = [cmd] + params
    length_byte = len_convention # Force user value
    
    # ID is separate in calculation?
    # Standard: 55 55 ID Len Cmd P1...
    # Checksum = ~(ID + Len + Cmd + P1...)
    
    check_payload = [servo_id, length_byte] + packet_body
    cs = checksum(check_payload)
    
    full_packet = [0x55, 0x55, servo_id, length_byte] + packet_body + [cs]
    
    print(f"[BusServo] Sending ID={servo_id} Limit=0-1000 (Len={length_byte}): {[hex(x) for x in full_packet]}")
    ser.write(bytearray(full_packet))
    time.sleep(0.05)

def send_lsc_style_limit(ser, servo_id, min_val, max_val):
    """
    Send LSC Controller Style Limit Packet (Hypothetical).
    Based on servo_driver_node.cpp Move: 55 55 Len(08) Cmd(03) Count(01) TimeL TimeH ID AngL AngH
    Proposed Limit: 55 55 Len Cmd(20) Count(01) 00 00 ID MinL MinH MaxL MaxH
    Assuming structure is similar.
    """
    # Move is 10 bytes total. Payload after 55 55 is 8 bytes.
    # Move Payload: Len(08) Cmd(03) Count(01) T(2) ID(1) P(2).
    # Limit Payload: Len(?) Cmd(20) Count(01) T(2 - Dummy) ID(1) P1(Min) P2(Max) -> 4 bytes.
    # Total params: 1(Count) + 2(DummyTime) + 1(ID) + 4(Min/Max) = 8 bytes.
    # Cmd takes 1. Len takes 1.
    # Total bytes after 55 55: Len + Cmd + 8 = 10?
    # If we follow Len = Total Bytes including Len?
    # Move: 08 (Len). Bytes: 03, 01, E8, 03, ID, AL, AH. (7 bytes).
    # 1(LenByte) + 7 = 8. matches 0x08.
    
    # So Limit Packet:
    # Bytes after Len: Cmd(1) + Count(1) + Dummy(2) + ID(1) + Min(2) + Max(2) = 9 bytes.
    # So Len should be 1 + 9 = 10 (0x0A).
    
    length_byte = 0x0A
    cmd = 0x14 # 20
    count = 0x01
    dummy_time = [0x00, 0x00] # Pass 0 time? Or Maybe 1000? Let's use 0.
    
    min_l = min_val & 0xFF
    min_h = (min_val >> 8) & 0xFF
    max_l = max_val & 0xFF
    max_h = (max_val >> 8) & 0xFF
    
    # 55 55 Len Cmd Count TimeL TimeH ID MinL MinH MaxL MaxH
    packet = [0x55, 0x55, length_byte, cmd, count] + dummy_time + [servo_id, min_l, min_h, max_l, max_h]
    
    print(f"[LSC-Hypothetical] Sending ID={servo_id}: {[hex(x) for x in packet]}")
    ser.write(bytearray(packet))
    time.sleep(0.05)


def main():
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyUSB0"
    servo_ids = [1, 2]
    if len(sys.argv) > 2:
        servo_ids = [int(sys.argv[2])]

    try:
        ser = serial.Serial(port, 9600, timeout=1)
        print(f"Opened {port} successfully.")
    except Exception as e:
        print(f"Error opening port: {e}")
        return

    for sid in servo_ids:
        print(f"--- Programming Servo {sid} ---")
        
        # Variation 1: Standard Bus Servo (Len=7) - Most docs
        send_bus_servo_limit(ser, sid, 0, 1000, len_convention=7)
        
        # Variation 2: Bus Servo (Len=6) - Mathematical (Cmd+4Params+1CS = 6)
        send_bus_servo_limit(ser, sid, 0, 1000, len_convention=6)
        
        # Variation 3: LSC Style (Tunneling/Controller Command)
        # Assuming the controller translates or we mimic the structure
        send_lsc_style_limit(ser, sid, 0, 1000)
    
    print("Done. Please power cycle specific servo driver/robot power if possible.")
    ser.close()

if __name__ == "__main__":
    main()
