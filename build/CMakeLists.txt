# -*- CMake -*-
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

# Set minimum version of cmake required to build this project
cmake_minimum_required (VERSION 2.8)
project (aurorafw)

# Check for dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(ROOT_DIR ..)
    set(SOURCE_DIR ${ROOT_DIR}/src)
endif()

include_directories(${ROOT_DIR}/include)

add_library (aurora-core-tlib SHARED ${SOURCE_DIR}/aurora-core-tlib/CircularShift.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/Endian.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/IOStream.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/String.cpp)

add_library (aurora-core SHARED ${SOURCE_DIR}/aurora-core/Application.cpp
                                ${SOURCE_DIR}/aurora-core/Debug.cpp)

add_library (aurora-gui SHARED ${SOURCE_DIR}/aurora-gui/Application.cpp
                               ${SOURCE_DIR}/aurora-gui/Label.cpp
                               ${SOURCE_DIR}/aurora-gui/Style.cpp
                               ${SOURCE_DIR}/aurora-gui/Window.cpp)

target_link_libraries(aurora-core aurora-core-tlib)
target_link_libraries(aurora-gui aurora-core)

set_target_properties(aurora-core-tlib PROPERTIES OUTPUT_NAME aurora-core-tlib)
set_target_properties(aurora-core PROPERTIES OUTPUT_NAME aurora-core)

set_target_properties(aurora-gui PROPERTIES
    OUTPUT_NAME
        aurora-gui

    COMPILE_FLAGS
        "pkg-config --cflags --libs gtk+-3.0"
)

# DEBUG !!!
#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()
