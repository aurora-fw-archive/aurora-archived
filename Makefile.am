# Process this file with automake to produce Makefile.in
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

# C++ Flags
AM_CXXFLAGS = -Wall -Wextra -std=c++14 -I../include/ `pkg-config --cflags --libs gtk+-3.0`
AM_CFLAGS = -Wall -Wno-unknown-pragmas -Wextra -std=c11 -I../include/ `pkg-config --cflags --libs gtk+-3.0`

# Library Information
lib_LTLIBRARIES = $(top_builddir)/../bin/libaurora.la $(top_builddir)/../bin/libaurorac.la

# Source files
__top_builddir_____bin_libaurora_la_SOURCES = ../src/GUI/Window.cpp \
                                              ../src/GUI/Application.cpp \
                                              ../src/GUI/Label.cpp \
                                              ../src/Info/RAM.cpp \
                                              ../src/Core/Application.cpp \
                                              ../src/Core/Debug.cpp \
                                              ../src/Shell/Color.cpp \
                                              ../src/Crypto/AES.cpp \
                                              ../src/Info/OS.cpp \
                                              ../src/Lib/IOStream.cpp \
                                              ../src/Shell/Input.cpp \
                                              ../src/Shell/Output.cpp \
                                              ../src/Lib/String.cpp \
                                              ../src/Lib/CircularShift.cpp

__top_builddir_____bin_libaurorac_la_SOURCES = ../src/Lib/Memory.c

# Headers
cincludedir = $(includedir)/Aurora/
cinclude_HEADERS = ../include/Aurora/Aurora.h

# Core Headers
coreincludedir = $(includedir)/Aurora/Core
coreinclude_HEADERS = ../include/Aurora/Core/Application.h \
                      ../include/Aurora/Core/Aurora.h \
                      ../include/Aurora/Core/Debug.h

# GUI Headers
guiincludedir = $(includedir)/Aurora/GUI
guiinclude_HEADERS = ../include/Aurora/GUI/Window.h \
                     ../include/Aurora/GUI/Application.h \
                     ../include/Aurora/GUI/Label.h \
                     ../include/Aurora/GUI/Layout.h

# Info Headers
infoincludedir = $(includedir)/Aurora/Info
infoinclude_HEADERS = ../include/Aurora/Info/RAM.h \
                      ../include/Aurora/Info/OS.h

# Lib Headers
libincludedir = $(includedir)/Aurora/Lib
libinclude_HEADERS = ../include/Aurora/Lib/Aurora.h \
                     ../include/Aurora/Lib/Endian.h \
                     ../include/Aurora/Lib/Type.h \
                     ../include/Aurora/Lib/Target.h \
                     ../include/Aurora/Lib/IOStream.h \
                     ../include/Aurora/Lib/String.h \
                     ../include/Aurora/Lib/CircularShift.h \
                     ../include/Aurora/Lib/Memory.h

# Shell Headers
shellincludedir = $(includedir)/Aurora/Shell
shellinclude_HEADERS = ../include/Aurora/Shell/Color.h \
                       ../include/Aurora/Shell/Log.h \
                       ../include/Aurora/Shell/Input.h \
                       ../include/Aurora/Shell/Output.h

# Crypto Headers
cryptoincludedir = $(includedir)/Aurora/Crypto
cryptoinclude_HEADERS = ../include/Aurora/Crypto/AES.h
