# Gripper Control Guide

## ✓ POSITION FEEDBACK ENABLED!
The simple gripper (EG2-4C2) **DOES** have position feedback via the Realman Python API!

## Solution
- Gripper is properly initialized via socket (Modbus) at startup
- **Actual position is READ from hardware** via `rm_get_gripper_state()` API
- Physical gripper position (`actpos`) is read continuously during data collection
- Position is normalized to 0-1 and included in the 14D state vector
- You can physically open/close the gripper during kinesthetic teaching and it will be automatically detected!

## Initialization (Automatic)
When `Hardware_Bridge_ROS2` starts, it:
1. Connects to each arm via socket (port 8080)
2. Sets tool voltage to 24V
3. Configures ModbusRTU mode (115200 baud)
4. Initializes gripper registers
5. Opens grippers to 100% (1000) for kinesthetic teaching

## Data Collection Controls

### Both Grippers
- `0` - Close to 0% (position = 0)
- `1` - Set to 10% (position = 100)
- `2` - Set to 20% (position = 200)
- `3` - Set to 30% (position = 300)
- `4` - Set to 40% (position = 400)
- `5` - Set to 50% (position = 500)
- `6` - Set to 60% (position = 600)
- `7` - Set to 70% (position = 700)
- `8` - Set to 80% (position = 800)
- `9` - Set to 90% (position = 900)
- `o` or `f` - Fully open to 100% (position = 1000)

### Individual Gripper Control
- `l0` - `l9` - Set LEFT gripper only (0%-90%)
- `r0` - `r9` - Set RIGHT gripper only (0%-90%)

Examples:
- `l5` - Left gripper to 50%, right unchanged
- `r8` - Right gripper to 80%, left unchanged
- `5` - Both grippers to 50%

## During Kinesthetic Teaching

### Option 1: Physical Gripper Control (RECOMMENDED)
1. Start episode with `s`
2. Physically move robot arms AND grippers to demonstrate pouring
3. The **actual gripper positions are automatically read** from hardware
4. Gripper state is recorded in real-time with the arm positions
5. Save episode with `y`

### Option 2: Keyboard Gripper Control
If you prefer to control gripper via keyboard (e.g., gripper is hard to physically move):
1. Start episode with `s`
2. Physically move robot arms
3. Press numeric keys (`0-9`, `o`) to adjust gripper positions
4. Commanded positions are sent to hardware and recorded
5. Save episode with `y`

## Technical Details

### State Vector (14D)
```python
[
    l_joint1, l_joint2, l_joint3, l_joint4, l_joint5, l_joint6,  # Left arm (6)
    l_gripper_norm,                                               # Left gripper (1) [0-1]
    r_joint1, r_joint2, r_joint3, r_joint4, r_joint5, r_joint6,  # Right arm (6)
    r_gripper_norm                                                # Right gripper (1) [0-1]
]
```

### Gripper Position Range
- Internal tracking: 0-1000 (raw gripper units)
- Physical range: 0-70mm
- Normalized for ML: 0.0-1.0 (divided by 1000)

### ROS Topics
- Command: `/left_arm_controller/rm_driver/set_gripper_position_cmd`
- Command: `/right_arm_controller/rm_driver/set_gripper_position_cmd`
- Result: `/left_arm_controller/rm_driver/set_gripper_position_result` (Bool only)
- Result: `/right_arm_controller/rm_driver/set_gripper_position_result` (Bool only)

**Note:** Result topics only indicate success/failure, NOT actual gripper position!

## Troubleshooting

### Gripper not responding?
1. Check if tool voltage is enabled (should happen automatically at startup)
2. Verify Modbus is configured (check Hardware_Bridge logs)
3. Try manual initialization via socket (see gripper.py)

### Need to read actual gripper position?
Unfortunately, the simple gripper hardware does NOT support this. You can only:
- Track the last commanded position (what we're doing)
- Manually verify gripper state during teaching

### Want more precise control?
You can modify `Hardware_Bridge_ROS2.set_gripper()` to accept any value 0-1000:
```python
self.hardware.set_gripper('left', 653)  # Set to 65.3%
```
