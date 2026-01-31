#!/usr/bin/env python3
"""
Keyboard Teleop for Joystick Step Control

Controls:
    W / ↑  : Forward
    S / ↓  : Backward
    A / ←  : Rotate Left
    D / →  : Rotate Right
    Q      : Forward + Left
    E      : Forward + Right
    SPACE  : Stop
    ESC    : Quit
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Vector3
import sys
import tty
import termios
import select
import time

INSTRUCTIONS = """
---------------------------
Keyboard Teleop Controller
---------------------------
   Q    W    E
   A    S    D

W/↑ : Forward      S/↓ : Backward
A/← : Rotate Left  D/→ : Rotate Right
Q   : Fwd + Left   E   : Fwd + Right
SPACE : Stop

HOLD to move, RELEASE to stop
ESC/Ctrl+C : Quit
---------------------------
"""

KEY_BINDINGS = {
    'w': (10.0, 0.0),
    's': (-10.0, 0.0),
    'a': (0.0, 10.0),
    'd': (0.0, -10.0),
    'q': (10.0, 5.0),
    'e': (10.0, -5.0),
    ' ': (0.0, 0.0),  # Explicit stop
}

ARROW_KEYS = {
    '\x1b[A': (10.0, 0.0),
    '\x1b[B': (-10.0, 0.0),
    '\x1b[D': (0.0, 10.0),
    '\x1b[C': (0.0, -10.0),
}


class KeyboardTeleop(Node):
    def __init__(self):
        super().__init__('keyboard_teleop')
        
        self.publisher = self.create_publisher(Vector3, '/joystick_input', 10)
        self.timer = self.create_timer(0.05, self.timer_callback)  # 20Hz
        
        self.linear = 0.0
        self.angular = 0.0
        self.last_key_time = time.time()
        self.key_timeout = 0.3  # INCREASED from 0.15 to 0.3
        
        self.old_settings = termios.tcgetattr(sys.stdin)
        
        print(INSTRUCTIONS)
        
    def get_key(self):
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.03)  # Slightly longer select timeout
        
        key = ''
        if rlist:
            key = sys.stdin.read(1)
            if key == '\x1b':
                rlist2, _, _ = select.select([sys.stdin], [], [], 0.01)
                if rlist2:
                    key += sys.stdin.read(2)
            
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.old_settings)
        return key
    
    def timer_callback(self):
        key = self.get_key()
        current_time = time.time()
        
        if key:
            if key == '\x1b' and len(key) == 1:
                self.shutdown()
                return
            if key == '\x03':
                self.shutdown()
                return
            
            if key in ARROW_KEYS:
                self.linear, self.angular = ARROW_KEYS[key]
                self.last_key_time = current_time
            elif key.lower() in KEY_BINDINGS:
                self.linear, self.angular = KEY_BINDINGS[key.lower()]
                self.last_key_time = current_time
        else:
            # No key - check timeout
            if current_time - self.last_key_time > self.key_timeout:
                if self.linear != 0.0 or self.angular != 0.0:
                    self.linear = 0.0
                    self.angular = 0.0
        
        msg = Vector3()
        msg.x = self.linear
        msg.y = self.angular
        msg.z = 0.0
        self.publisher.publish(msg)
        
        status = "MOVING" if (self.linear != 0 or self.angular != 0) else "STOP"
        print(f"\rLin: {self.linear:5.1f}  Ang: {self.angular:5.1f}  [{status}]   ", end='', flush=True)
    
    def shutdown(self):
        msg = Vector3()
        self.publisher.publish(msg)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.old_settings)
        print("\n\nBye!")
        rclpy.shutdown()

    def __del__(self):
        try:
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.old_settings)
        except:
            pass


def main(args=None):
    rclpy.init(args=args)
    node = KeyboardTeleop()
    try:
        rclpy.spin(node)
    except:
        pass
    finally:
        try:
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, node.old_settings)
        except:
            pass


if __name__ == '__main__':
    main()