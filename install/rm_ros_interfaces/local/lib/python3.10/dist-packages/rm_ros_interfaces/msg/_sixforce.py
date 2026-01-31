# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_ros_interfaces:msg/Sixforce.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Sixforce(type):
    """Metaclass of message 'Sixforce'."""

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
                'rm_ros_interfaces.msg.Sixforce')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sixforce
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sixforce
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sixforce
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sixforce
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sixforce

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Sixforce(metaclass=Metaclass_Sixforce):
    """Message class 'Sixforce'."""

    __slots__ = [
        '_force_fx',
        '_force_fy',
        '_force_fz',
        '_force_mx',
        '_force_my',
        '_force_mz',
    ]

    _fields_and_field_types = {
        'force_fx': 'float',
        'force_fy': 'float',
        'force_fz': 'float',
        'force_mx': 'float',
        'force_my': 'float',
        'force_mz': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.force_fx = kwargs.get('force_fx', float())
        self.force_fy = kwargs.get('force_fy', float())
        self.force_fz = kwargs.get('force_fz', float())
        self.force_mx = kwargs.get('force_mx', float())
        self.force_my = kwargs.get('force_my', float())
        self.force_mz = kwargs.get('force_mz', float())

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
        if self.force_fx != other.force_fx:
            return False
        if self.force_fy != other.force_fy:
            return False
        if self.force_fz != other.force_fz:
            return False
        if self.force_mx != other.force_mx:
            return False
        if self.force_my != other.force_my:
            return False
        if self.force_mz != other.force_mz:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def force_fx(self):
        """Message field 'force_fx'."""
        return self._force_fx

    @force_fx.setter
    def force_fx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_fx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_fx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_fx = value

    @builtins.property
    def force_fy(self):
        """Message field 'force_fy'."""
        return self._force_fy

    @force_fy.setter
    def force_fy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_fy' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_fy' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_fy = value

    @builtins.property
    def force_fz(self):
        """Message field 'force_fz'."""
        return self._force_fz

    @force_fz.setter
    def force_fz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_fz' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_fz' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_fz = value

    @builtins.property
    def force_mx(self):
        """Message field 'force_mx'."""
        return self._force_mx

    @force_mx.setter
    def force_mx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_mx' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_mx' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_mx = value

    @builtins.property
    def force_my(self):
        """Message field 'force_my'."""
        return self._force_my

    @force_my.setter
    def force_my(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_my' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_my' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_my = value

    @builtins.property
    def force_mz(self):
        """Message field 'force_mz'."""
        return self._force_mz

    @force_mz.setter
    def force_mz(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_mz' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_mz' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_mz = value
