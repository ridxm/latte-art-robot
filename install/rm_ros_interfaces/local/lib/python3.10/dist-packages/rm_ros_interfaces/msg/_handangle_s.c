// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_ros_interfaces:msg/Handangle.idl
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
#include "rm_ros_interfaces/msg/detail/handangle__struct.h"
#include "rm_ros_interfaces/msg/detail/handangle__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_ros_interfaces__msg__handangle__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("rm_ros_interfaces.msg._handangle.Handangle", full_classname_dest, 42) == 0);
  }
  rm_ros_interfaces__msg__Handangle * ros_message = _ros_message;
  {  // hand_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "hand_angle");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_INT16);
      Py_ssize_t size = 6;
      int16_t * dest = ros_message->hand_angle;
      for (Py_ssize_t i = 0; i < size; ++i) {
        int16_t tmp = *(npy_int16 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(int16_t));
      }
      Py_DECREF(seq_field);
    }
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_ros_interfaces__msg__handangle__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Handangle */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_ros_interfaces.msg._handangle");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Handangle");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_ros_interfaces__msg__Handangle * ros_message = (rm_ros_interfaces__msg__Handangle *)raw_ros_message;
  {  // hand_angle
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "hand_angle");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_INT16);
    assert(sizeof(npy_int16) == sizeof(int16_t));
    npy_int16 * dst = (npy_int16 *)PyArray_GETPTR1(seq_field, 0);
    int16_t * src = &(ros_message->hand_angle[0]);
    memcpy(dst, src, 6 * sizeof(int16_t));
    Py_DECREF(field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
