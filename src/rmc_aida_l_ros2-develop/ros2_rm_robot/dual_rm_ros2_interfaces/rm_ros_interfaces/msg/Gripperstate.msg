# Gripper state feedback message
bool enable_state    # Gripper enabled (0=disabled, 1=enabled)
bool status          # Online status (0=offline, 1=online)
int32 error          # Error flags
int32 mode           # Work state: 1=open idle, 2=closed idle, 3=stopped, 4=closing, 5=opening, 6=force stopped
int32 current_force  # Current force in grams
int32 temperature    # Temperature in Celsius
int32 actpos         # Actual gripper position (0-1000, 0=closed, 1000=70mm open)
