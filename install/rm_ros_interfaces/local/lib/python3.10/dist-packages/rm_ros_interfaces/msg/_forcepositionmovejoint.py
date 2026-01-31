# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_ros_interfaces:msg/Forcepositionmovejoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'joint'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Forcepositionmovejoint(type):
    """Metaclass of message 'Forcepositionmovejoint'."""

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
                'rm_ros_interfaces.msg.Forcepositionmovejoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__forcepositionmovejoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__forcepositionmovejoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__forcepositionmovejoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__forcepositionmovejoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__forcepositionmovejoint

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Forcepositionmovejoint(metaclass=Metaclass_Forcepositionmovejoint):
    """Message class 'Forcepositionmovejoint'."""

    __slots__ = [
        '_joint',
        '_sensor',
        '_mode',
        '_dir',
        '_force',
        '_follow',
        '_dof',
    ]

    _fields_and_field_types = {
        'joint': 'sequence<float>',
        'sensor': 'uint8',
        'mode': 'uint8',
        'dir': 'int16',
        'force': 'float',
        'follow': 'boolean',
        'dof': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.joint = array.array('f', kwargs.get('joint', []))
        self.sensor = kwargs.get('sensor', int())
        self.mode = kwargs.get('mode', int())
        self.dir = kwargs.get('dir', int())
        self.force = kwargs.get('force', float())
        self.follow = kwargs.get('follow', bool())
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
        if self.sensor != other.sensor:
            return False
        if self.mode != other.mode:
            return False
        if self.dir != other.dir:
            return False
        if self.force != other.force:
            return False
        if self.follow != other.follow:
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

    @builtins.property  # noqa: A003
    def dir(self):  # noqa: A003
        """Message field 'dir'."""
        return self._dir

    @dir.setter  # noqa: A003
    def dir(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dir' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'dir' field must be an integer in [-32768, 32767]"
        self._dir = value

    @builtins.property
    def force(self):
        """Message field 'force'."""
        return self._force

    @force.setter
    def force(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force = value

    @builtins.property
    def follow(self):
        """Message field 'follow'."""
        return self._follow

    @follow.setter
    def follow(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'follow' field must be of type 'bool'"
        self._follow = value

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
