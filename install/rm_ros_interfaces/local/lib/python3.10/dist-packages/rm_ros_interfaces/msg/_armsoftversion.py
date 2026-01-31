# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_ros_interfaces:msg/Armsoftversion.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Armsoftversion(type):
    """Metaclass of message 'Armsoftversion'."""

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
                'rm_ros_interfaces.msg.Armsoftversion')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__armsoftversion
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__armsoftversion
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__armsoftversion
            cls._TYPE_SUPPORT = module.type_support_msg__msg__armsoftversion
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__armsoftversion

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Armsoftversion(metaclass=Metaclass_Armsoftversion):
    """Message class 'Armsoftversion'."""

    __slots__ = [
        '_planversion',
        '_ctrlversion',
        '_kernal1',
        '_kernal2',
        '_productversion',
    ]

    _fields_and_field_types = {
        'planversion': 'string',
        'ctrlversion': 'string',
        'kernal1': 'string',
        'kernal2': 'string',
        'productversion': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.planversion = kwargs.get('planversion', str())
        self.ctrlversion = kwargs.get('ctrlversion', str())
        self.kernal1 = kwargs.get('kernal1', str())
        self.kernal2 = kwargs.get('kernal2', str())
        self.productversion = kwargs.get('productversion', str())

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
        if self.planversion != other.planversion:
            return False
        if self.ctrlversion != other.ctrlversion:
            return False
        if self.kernal1 != other.kernal1:
            return False
        if self.kernal2 != other.kernal2:
            return False
        if self.productversion != other.productversion:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def planversion(self):
        """Message field 'planversion'."""
        return self._planversion

    @planversion.setter
    def planversion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'planversion' field must be of type 'str'"
        self._planversion = value

    @builtins.property
    def ctrlversion(self):
        """Message field 'ctrlversion'."""
        return self._ctrlversion

    @ctrlversion.setter
    def ctrlversion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ctrlversion' field must be of type 'str'"
        self._ctrlversion = value

    @builtins.property
    def kernal1(self):
        """Message field 'kernal1'."""
        return self._kernal1

    @kernal1.setter
    def kernal1(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'kernal1' field must be of type 'str'"
        self._kernal1 = value

    @builtins.property
    def kernal2(self):
        """Message field 'kernal2'."""
        return self._kernal2

    @kernal2.setter
    def kernal2(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'kernal2' field must be of type 'str'"
        self._kernal2 = value

    @builtins.property
    def productversion(self):
        """Message field 'productversion'."""
        return self._productversion

    @productversion.setter
    def productversion(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'productversion' field must be of type 'str'"
        self._productversion = value
