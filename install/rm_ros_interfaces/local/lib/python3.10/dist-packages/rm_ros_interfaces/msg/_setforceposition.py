# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_ros_interfaces:msg/Setforceposition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Setforceposition(type):
    """Metaclass of message 'Setforceposition'."""

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
                'rm_ros_interfaces.msg.Setforceposition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__setforceposition
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__setforceposition
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__setforceposition
            cls._TYPE_SUPPORT = module.type_support_msg__msg__setforceposition
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__setforceposition

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Setforceposition(metaclass=Metaclass_Setforceposition):
    """Message class 'Setforceposition'."""

    __slots__ = [
        '_sensor',
        '_mode',
        '_direction',
        '_n',
        '_block',
    ]

    _fields_and_field_types = {
        'sensor': 'uint8',
        'mode': 'uint8',
        'direction': 'uint8',
        'n': 'int16',
        'block': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.sensor = kwargs.get('sensor', int())
        self.mode = kwargs.get('mode', int())
        self.direction = kwargs.get('direction', int())
        self.n = kwargs.get('n', int())
        self.block = kwargs.get('block', bool())

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
        if self.sensor != other.sensor:
            return False
        if self.mode != other.mode:
            return False
        if self.direction != other.direction:
            return False
        if self.n != other.n:
            return False
        if self.block != other.block:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sensor(self):
        """Message field 'sensor'."""
        return self._sensor

    @sensor.setter
    def sensor(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sensor' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sensor' field must be an unsigned integer in [0, 255]"
        self._sensor = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'direction' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'direction' field must be an unsigned integer in [0, 255]"
        self._direction = value

    @builtins.property
    def n(self):
        """Message field 'n'."""
        return self._n

    @n.setter
    def n(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'n' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'n' field must be an integer in [-32768, 32767]"
        self._n = value

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
