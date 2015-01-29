#if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
#  message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the source code and call cmake from there")
#endif()

cmake_minimum_required(VERSION 2.8)

# set Modules path to find dependencies
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# define a macro that helps defining an option
macro(vsge_set_option var default type docstring)
  if (NOT DEFINED ${var})
    set(${var} ${default})
  endif()
  set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# project name
project("VSGE")

# set version numbers
set(VSGE_VERSION_MAJOR 0)
set(VSGE_VERSION_MINOR 1)
set(VSGE_VERSION_PATCH 0)

# TODO(naum): Do better way
# set C++11 as the standard compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# include VSGE headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_subdirectory(src/VSGE)

# examples subdirectory
vsge_set_option(VSGE_BUILD_EXAMPLES FALSE BOOL "TRUE to build the SFML examples. FALSE to ignore them")

if(VSGE_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
