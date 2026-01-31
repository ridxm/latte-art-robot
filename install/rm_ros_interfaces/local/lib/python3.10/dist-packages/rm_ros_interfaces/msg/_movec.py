# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_ros_interfaces:msg/Movec.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Movec(type):
    """Metaclass of message 'Movec'."""

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
                'rm_ros_interfaces.msg.Movec')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__movec
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__movec
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__movec
            cls._TYPE_SUPPORT = module.type_support_msg__msg__movec
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__movec

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


class Movec(metaclass=Metaclass_Movec):
    """Message class 'Movec'."""

    __slots__ = [
        '_pose_mid',
        '_pose_end',
        '_speed',
        '_trajectory_connect',
        '_block',
        '_loop',
    ]

    _fields_and_field_types = {
        'pose_mid': 'geometry_msgs/Pose',
        'pose_end': 'geometry_msgs/Pose',
        'speed': 'uint8',
        'trajectory_connect': 'uint8',
        'block': 'boolean',
        'loop': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Pose
        self.pose_mid = kwargs.get('pose_mid', Pose())
        from geometry_msgs.msg import Pose
        self.pose_end = kwargs.get('pose_end', Pose())
        self.speed = kwargs.get('speed', int())
        self.trajectory_connect = kwargs.get('trajectory_connect', int())
        self.block = kwargs.get('block', bool())
        self.loop = kwargs.get('loop', int())

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
        if self.pose_mid != other.pose_mid:
            return False
        if self.pose_end != other.pose_end:
            return False
        if self.speed != other.speed:
            return False
        if self.trajectory_connect != other.trajectory_connect:
            return False
        if self.block != other.block:
            return False
        if self.loop != other.loop:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pose_mid(self):
        """Message field 'pose_mid'."""
        return self._pose_mid

    @pose_mid.setter
    def pose_mid(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_mid' field must be a sub message of type 'Pose'"
        self._pose_mid = value

    @builtins.property
    def pose_end(self):
        """Message field 'pose_end'."""
        return self._pose_end

    @pose_end.setter
    def pose_end(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_end' field must be a sub message of type 'Pose'"
        self._pose_end = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'speed' field must be an unsigned integer in [0, 255]"
        self._speed = value

    @builtins.property
    def trajectory_connect(self):
        """Message field 'trajectory_connect'."""
        return self._trajectory_connect

    @trajectory_connect.setter
    def trajectory_connect(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trajectory_connect' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'trajectory_connect' field must be an unsigned integer in [0, 255]"
        self._trajectory_connect = value

    @builtins.property
    def block(self):
        """Message field 'block'."""
        return self._block

    @block.setter
    def block(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'block' field must be of type 'bool'"
        self._block = value

    @builtins.property
    def loop(self):
        """Message field 'loop'."""
        return self._loop

    @loop.setter
    def loop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'loop' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'loop' field must be an unsigned integer in [0, 255]"
        self._loop = value
