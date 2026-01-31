# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_ros_interfaces:msg/Armstate.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'joint'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Armstate(type):
    """Metaclass of message 'Armstate'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rm_ros_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_ros_interfaces.msg.Armstate')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__armstate
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__armstate
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__armstate
            cls._TYPE_SUPPORT = module.type_support_msg__msg__armstate
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__armstate

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Armstate(metaclass=Metaclass_Armstate):
    """Message class 'Armstate'."""

    __slots__ = [
        '_joint',
        '_pose',
        '_arm_err',
        '_sys_err',
        '_dof',
    ]

    _fields_and_field_types = {
        'joint': 'sequence<float>',
        'pose': 'geometry_msgs/Pose',
        'arm_err': 'uint16',
        'sys_err': 'uint16',
        'dof': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.joint = array.array('f', kwargs.get('joint', []))
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        self.arm_err = kwargs.get('arm_err', int())
        self.sys_err = kwargs.get('sys_err', int())
        self.dof = kwargs.get('dof', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.joint != other.joint:
            return False
        if self.pose != other.pose:
            return False
        if self.arm_err != other.arm_err:
            return False
        if self.sys_err != other.sys_err:
            return False
        if self.dof != other.dof:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def joint(self):
        """Message field 'joint'."""
        return self._joint

    @joint.setter
    def joint(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint' array.array() must have the type code of 'f'"
            self._joint = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint = array.array('f', value)

    @builtins.property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @builtins.property
    def arm_err(self):
        """Message field 'arm_err'."""
        return self._arm_err

    @arm_err.setter
    def arm_err(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'arm_err' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'arm_err' field must be an unsigned integer in [0, 65535]"
        self._arm_err = value

    @builtins.property
    def sys_err(self):
        """Message field 'sys_err'."""
        return self._sys_err

    @sys_err.setter
    def sys_err(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sys_err' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'sys_err' field must be an unsigned integer in [0, 65535]"
        self._sys_err = value

    @builtins.property
    def dof(self):
        """Message field 'dof'."""
        return self._dof

    @dof.setter
    def dof(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dof' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dof' field must be an unsigned integer in [0, 255]"
        self._dof = value
