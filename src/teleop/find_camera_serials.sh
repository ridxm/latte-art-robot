#!/bin/bash
# Helper script to find RealSense camera serial numbers
# Run this to identify which camera is which

echo "=========================================="
echo "RealSense Camera Detection"
echo "=========================================="
echo ""
echo "Checking for connected RealSense cameras..."
echo ""

if ! command -v rs-enumerate-devices &> /dev/null; then
    echo "ERROR: rs-enumerate-devices not found"
    echo "Install RealSense SDK: sudo apt install librealsense2-utils"
    exit 1
fi

rs-enumerate-devices | grep -E "Device info|Serial Number|Name"

echo ""
echo "=========================================="
echo "Next steps:"
echo "1. Identify which serial number corresponds to:"
echo "   - Top/overhead camera"
echo "   - Left wrist camera"
echo "   - Right wrist camera"
echo ""
echo "2. Edit launch_drivers.py and add serial numbers:"
echo "   'serial_no_1:=<SERIAL_TOP>',"
echo "   'serial_no_2:=<SERIAL_LEFT_WRIST>',"
echo "   'serial_no_3:=<SERIAL_RIGHT_WRIST>',"
echo "=========================================="
