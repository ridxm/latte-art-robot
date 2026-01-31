// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_ros_interfaces:msg/Sixforce.idl
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
#include "rm_ros_interfaces/msg/detail/sixforce__struct.h"
#include "rm_ros_interfaces/msg/detail/sixforce__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_ros_interfaces__msg__sixforce__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("rm_ros_interfaces.msg._sixforce.Sixforce", full_classname_dest, 40) == 0);
  }
  rm_ros_interfaces__msg__Sixforce * ros_message = _ros_message;
  {  // force_fx
    PyObject * field = PyObject_GetAttrString(_pymsg, "force_fx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->force_fx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // force_fy
    PyObject * field = PyObject_GetAttrString(_pymsg, "force_fy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->force_fy = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // force_fz
    PyObject * field = PyObject_GetAttrString(_pymsg, "force_fz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->force_fz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // force_mx
    PyObject * field = PyObject_GetAttrString(_pymsg, "force_mx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->force_mx = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // force_my
    PyObject * field = PyObject_GetAttrString(_pymsg, "force_my");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->force_my = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // force_mz
    PyObject * field = PyObject_GetAttrString(_pymsg, "force_mz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->force_mz = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_ros_interfaces__msg__sixforce__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Sixforce */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_ros_interfaces.msg._sixforce");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Sixforce");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_ros_interfaces__msg__Sixforce * ros_message = (rm_ros_interfaces__msg__Sixforce *)raw_ros_message;
  {  // force_fx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->force_fx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force_fx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // force_fy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->force_fy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force_fy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // force_fz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->force_fz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force_fz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // force_mx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->force_mx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force_mx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // force_my
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->force_my);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force_my", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // force_mz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->force_mz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "force_mz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
