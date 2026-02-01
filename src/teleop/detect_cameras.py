#!/usr/bin/env python3
"""
Detect all connected cameras (RealSense and ZED)
"""

import subprocess
import os

def detect_realsense_cameras():
    """Detect RealSense cameras"""
    print("\n" + "="*60)
    print("REALSENSE CAMERAS")
    print("="*60)

    try:
        result = subprocess.run(
            ['rs-enumerate-devices'],
            capture_output=True,
            text=True,
            timeout=5
        )

        cameras = []
        current_cam = {}

        for line in result.stdout.split('\n'):
            if 'Device info:' in line:
                if current_cam:
                    cameras.append(current_cam)
                current_cam = {}
            elif 'Name' in line and ':' in line:
                current_cam['name'] = line.split(':', 1)[1].strip()
            elif 'Serial Number' in line:
                current_cam['serial'] = line.split(':', 1)[1].strip()
            elif 'USB' in line and 'type' in line.lower():
                current_cam['usb'] = line.split(':', 1)[1].strip()
            elif 'physical port' in line.lower():
                current_cam['port'] = line.split(':', 1)[1].strip()

        if current_cam:
            cameras.append(current_cam)

        if cameras:
            for i, cam in enumerate(cameras):
                print(f"\nRealSense #{i+1}:")
                print(f"  Name: {cam.get('name', 'Unknown')}")
                print(f"  Serial: {cam.get('serial', 'Unknown')}")
                print(f"  USB Type: {cam.get('usb', 'Unknown')}")
                print(f"  Port: {cam.get('port', 'Unknown')}")
        else:
            print("  No RealSense cameras found")

        return cameras

    except FileNotFoundError:
        print("  rs-enumerate-devices not found (install librealsense2-utils)")
        return []
    except Exception as e:
        print(f"  Error: {e}")
        return []

def detect_zed_cameras():
    """Detect ZED cameras"""
    print("\n" + "="*60)
    print("ZED CAMERAS")
    print("="*60)

    # Try ZED SDK
    try:
        result = subprocess.run(
            ['ZED_Explorer', '--list'],
            capture_output=True,
            text=True,
            timeout=5
        )

        if 'ZED' in result.stdout:
            print(result.stdout)
        else:
            print("  No ZED cameras detected via ZED_Explorer")
    except FileNotFoundError:
        print("  ZED_Explorer not found")
    except Exception as e:
        print(f"  Error with ZED_Explorer: {e}")

    # Alternative: check USB devices for ZED
    print("\n  Checking USB devices for ZED cameras...")
    try:
        result = subprocess.run(
            ['lsusb'],
            capture_output=True,
            text=True
        )

        zed_devices = []
        for line in result.stdout.split('\n'):
            if 'Stereo' in line or 'ZED' in line.upper() or '2b03' in line.lower():
                zed_devices.append(line)
                print(f"    Found: {line}")

        if not zed_devices:
            print("    No ZED cameras found in USB devices")

    except Exception as e:
        print(f"  Error checking USB: {e}")

def detect_all_video_devices():
    """List all video devices"""
    print("\n" + "="*60)
    print("ALL VIDEO DEVICES")
    print("="*60)

    try:
        video_devices = []
        for i in range(20):  # Check video0 to video19
            dev = f'/dev/video{i}'
            if os.path.exists(dev):
                # Get device info
                try:
                    result = subprocess.run(
                        ['v4l2-ctl', '--device', dev, '--info'],
                        capture_output=True,
                        text=True,
                        timeout=1
                    )

                    name = "Unknown"
                    for line in result.stdout.split('\n'):
                        if 'Card type' in line:
                            name = line.split(':', 1)[1].strip()
                            break

                    video_devices.append((dev, name))
                    print(f"  {dev}: {name}")

                except:
                    video_devices.append((dev, "Unknown"))
                    print(f"  {dev}: (info not available)")

        if not video_devices:
            print("  No video devices found")

        return video_devices

    except Exception as e:
        print(f"  Error: {e}")
        return []

def main():
    print("\n" + "="*60)
    print("CAMERA DETECTION TOOL")
    print("="*60)
    print("\nThis will help identify your cameras for data collection")
    print("You need to identify:")
    print("  - Head/overhead camera (for workspace view)")
    print("  - Left wrist camera")
    print("  - Right wrist camera")

    realsense_cams = detect_realsense_cameras()
    detect_zed_cameras()
    video_devs = detect_all_video_devices()

    print("\n" + "="*60)
    print("NEXT STEPS")
    print("="*60)
    print("\n1. Identify which camera is which by:")
    print("   - Looking at USB port locations")
    print("   - Camera serial numbers")
    print("   - Physical mounting position")

    print("\n2. For RealSense cameras, note the serial numbers")
    print("   For ZED cameras, note the /dev/video device")

    print("\n3. Update launch_drivers.py with the correct:")
    print("   - Camera types (RealSense vs ZED)")
    print("   - Serial numbers or device paths")
    print("   - Topic mappings")

    print("\n" + "="*60)

if __name__ == '__main__':
    main()
