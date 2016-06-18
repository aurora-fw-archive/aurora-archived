# Process this file with automake to produce Makefile.in
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

# C++ Flags
AM_CXXFLAGS = -Wall -Wextra -std=c++14 -lGL -lGLU -lglut -I../include/ `pkg-config --cflags --libs gtk+-3.0`

# Library Information
lib_LTLIBRARIES = $(top_builddir)/../bin/libaurora.la

# Source files
__top_builddir_____bin_libaurora_la_SOURCES = ../src/GUI/Window.cpp \
                                              ../src/GUI/Application.cpp \
                                              ../src/GUI/Label.cpp \
                                              ../src/Info/RAM.cpp \
                                              ../src/Core/Application.cpp \
                                              ../src/Core/Macros.cpp \
                                              ../src/Core/Debug.cpp \
                                              ../src/Shell/Color.cpp \
                                              ../src/Crypto/AES.cpp \
                                              ../src/Info/OS.cpp

# Headers
cincludedir = $(includedir)/Aurora/
cinclude_HEADERS = ../include/Aurora/Aurora.h

# Core Headers
coreincludedir = $(includedir)/Aurora/Core
coreinclude_HEADERS = ../include/Aurora/Core/Application.h \
                      ../include/Aurora/Core/Aurora.h \
                      ../include/Aurora/Core/Macros.h \
                      ../include/Aurora/Core/Targets.h \
                      ../include/Aurora/Core/Typedef.h \
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
                   
# Shell Headers
shellincludedir = $(includedir)/Aurora/Shell
shellinclude_HEADERS = ../include/Aurora/Shell/Color.h \
                       ../include/Aurora/Shell/ColorType.h \
                       ../include/Aurora/Shell/Input.h \
                       ../include/Aurora/Shell/Log.h \
                       ../include/Aurora/Shell/Output.h

# Crypto Headers
cryptoincludedir = $(includedir)/Aurora/Crypto
cryptoinclude_HEADERS = ../include/Aurora/Crypto/AES.h