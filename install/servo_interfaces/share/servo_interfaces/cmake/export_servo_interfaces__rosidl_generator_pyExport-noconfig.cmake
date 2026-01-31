#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "servo_interfaces::servo_interfaces__rosidl_generator_py" for configuration ""
set_property(TARGET servo_interfaces::servo_interfaces__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(servo_interfaces::servo_interfaces__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libservo_interfaces__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libservo_interfaces__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS servo_interfaces::servo_interfaces__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_servo_interfaces::servo_interfaces__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libservo_interfaces__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
