#!/usr/bin/env python3
"""Test camera feeds - shows what each camera sees"""

import cv2
import numpy as np
import time

def test_cameras():
    print('='*60)
    print('CAMERA TEST')
    print('='*60)
    print('Searching for cameras...')
    print()
    
    # Try multiple camera indices
    cameras = {}
    for idx in range(10):
        cap = cv2.VideoCapture(idx)
        if cap.isOpened():
            ret, frame = cap.read()
            if ret:
                h, w = frame.shape[:2]
                print(f'  Camera {idx}: {w}x{h} - FOUND')
                cameras[idx] = cap
            else:
                cap.release()
        
    if not cameras:
        print('No cameras found!')
        return
        
    print()
    print(f'Found {len(cameras)} camera(s)')
    print()
    print('Press q to quit, s to save snapshot')
    print('='*60)
    
    # Create windows
    for idx in cameras:
        cv2.namedWindow(f'Camera {idx}', cv2.WINDOW_NORMAL)
        cv2.resizeWindow(f'Camera {idx}', 640, 480)
    
    snapshot_count = 0
    
    try:
        while True:
            # Capture and display all cameras
            for idx, cap in cameras.items():
                ret, frame = cap.read()
                if ret:
                    # Add label
                    cv2.putText(frame, f'Camera {idx}', (10, 30), 
                               cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
                    cv2.imshow(f'Camera {idx}', frame)
            
            key = cv2.waitKey(1) & 0xFF
            
            if key == ord('q'):
                print('Quitting...')
                break
            elif key == ord('s'):
                # Save snapshots
                for idx, cap in cameras.items():
                    ret, frame = cap.read()
                    if ret:
                        filename = f'snapshot_cam{idx}_{snapshot_count}.jpg'
                        cv2.imwrite(filename, frame)
                        print(f'Saved {filename}')
                snapshot_count += 1
                
    finally:
        for cap in cameras.values():
            cap.release()
        cv2.destroyAllWindows()
        
    print('Done!')


if __name__ == '__main__':
    test_cameras()
