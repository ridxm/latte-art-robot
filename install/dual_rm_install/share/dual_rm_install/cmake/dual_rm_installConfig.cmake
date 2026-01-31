# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dual_rm_install_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dual_rm_install_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dual_rm_install_FOUND FALSE)
  elseif(NOT dual_rm_install_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dual_rm_install_FOUND FALSE)
  endif()
  return()
endif()
set(_dual_rm_install_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dual_rm_install_FIND_QUIETLY)
  message(STATUS "Found dual_rm_install: 0.0.0 (${dual_rm_install_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dual_rm_install' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dual_rm_install_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dual_rm_install_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${dual_rm_install_DIR}/${_extra}")
endforeach()
