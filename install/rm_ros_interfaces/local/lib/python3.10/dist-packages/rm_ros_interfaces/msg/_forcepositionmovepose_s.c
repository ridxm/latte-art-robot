// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_ros_interfaces:msg/Forcepositionmovepose.idl
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
#include "rm_ros_interfaces/msg/detail/forcepositionmovepose__struct.h"
#include "rm_ros_interfaces/msg/detail/forcepositionmovepose__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool rm_ros_interfaces__msg__forcepositionmovepose__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[67];
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
    assert(strncmp("rm_ros_interfaces.msg._forcepositionmovepose.Forcepositionmovepose", full_classname_dest, 66) == 0);
  }
  rm_ros_interfaces__msg__Forcepositionmovepose * ros_message = _ros_message;
  {  // pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // sensor
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sensor = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dir
    PyObject * field = PyObject_GetAttrString(_pymsg, "dir");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dir = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // force
    PyObject * field = PyObject_GetAttrString(_pymsg, "force");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->force = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // follow
    PyObject * field = PyObject_GetAttrString(_pymsg, "follow");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->follow = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_ros_interfaces__msg__forcepositionmovepose__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Forcepositionmovepose */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_ros_interfaces.msg._forcepositionmovepose");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Forcepositionmovepose");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_ros_interfaces__msg__Forcepositionmovepose * ros_message = (rm_ros_interfaces__msg__Forcepositionmovepose *)raw_ros_message;
  {  // pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sensor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dir
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dir);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dir", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // force
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->force);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // follow
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->follow ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "follow", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
