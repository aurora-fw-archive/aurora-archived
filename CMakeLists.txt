# -*- CMake -*-
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

cmake_minimum_required (VERSION 2.8.11)

project (Aurora)
set(CMAKE_BUILD_TYPE Release)

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 -I../include/ `pkg-config --cflags --libs gtk+-3.0`"
      CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library (Aurora SHARED src/GUI/Window.cpp \
                    src/GUI/Application.cpp \
                    src/GUI/Label.cpp \
                    src/Info/RAM.cpp \
                    src/Core/Application.cpp \
                    src/Core/Debug.cpp \
                    src/Shell/Color.cpp \
                    src/Crypto/AES.cpp \
                    src/Info/OS.cpp)

set_target_properties(Aurora PROPERTIES OUTPUT_NAME aurora)
