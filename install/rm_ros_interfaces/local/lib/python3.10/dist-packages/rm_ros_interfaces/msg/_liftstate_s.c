// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_ros_interfaces:msg/Liftstate.idl
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
#include "rm_ros_interfaces/msg/detail/liftstate__struct.h"
#include "rm_ros_interfaces/msg/detail/liftstate__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_ros_interfaces__msg__liftstate__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("rm_ros_interfaces.msg._liftstate.Liftstate", full_classname_dest, 42) == 0);
  }
  rm_ros_interfaces__msg__Liftstate * ros_message = _ros_message;
  {  // height
    PyObject * field = PyObject_GetAttrString(_pymsg, "height");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->height = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // current
    PyObject * field = PyObject_GetAttrString(_pymsg, "current");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // err_flag
    PyObject * field = PyObject_GetAttrString(_pymsg, "err_flag");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->err_flag = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_ros_interfaces__msg__liftstate__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Liftstate */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_ros_interfaces.msg._liftstate");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Liftstate");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_ros_interfaces__msg__Liftstate * ros_message = (rm_ros_interfaces__msg__Liftstate *)raw_ros_message;
  {  // height
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // err_flag
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->err_flag);
    {
      int rc = PyObject_SetAttrString(_pymessage, "err_flag", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
