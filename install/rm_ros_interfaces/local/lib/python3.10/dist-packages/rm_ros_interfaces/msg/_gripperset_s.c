// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_ros_interfaces:msg/Gripperset.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rm_ros_interfaces/msg/detail/gripperset__struct.h"
#include "rm_ros_interfaces/msg/detail/gripperset__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_ros_interfaces__msg__gripperset__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rm_ros_interfaces.msg._gripperset.Gripperset", full_classname_dest, 44) == 0);
  }
  rm_ros_interfaces__msg__Gripperset * ros_message = _ros_message;
  {  // position
    PyObject * field = PyObject_GetAttrString(_pymsg, "position");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->position = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // block
    PyObject * field = PyObject_GetAttrString(_pymsg, "block");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->block = (Py_True == field);
    Py_DECREF(field);
  }
  {  // timeout
    PyObject * field = PyObject_GetAttrString(_pymsg, "timeout");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timeout = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_ros_interfaces__msg__gripperset__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Gripperset */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_ros_interfaces.msg._gripperset");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Gripperset");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_ros_interfaces__msg__Gripperset * ros_message = (rm_ros_interfaces__msg__Gripperset *)raw_ros_message;
  {  // position
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // block
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->block ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "block", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // timeout
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->timeout);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timeout", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
