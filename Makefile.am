# Process this file with automake to produce Makefile.in
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

AM_CXXFLAGS = -Wall -Wextra -std=c++14 -lGL -lGLU -lglut -I../include/ `pkg-config --cflags --libs gtk+-3.0`
lib_LTLIBRARIES = $(top_builddir)/../bin/libaurora.la
__top_builddir_____bin_libaurora_la_SOURCES = ../src/GUI/Window.cpp \
                                              ../src/Info/RAM.cpp \
                                              ../src/Shell/Log.cpp \
                                              ../src/Aurora/Application.cpp \
                                              ../src/GUI/Application.cpp \
                                              ../src/GUI/Label.cpp \
                                              ../src/Aurora/Macros.cpp \
                                              ../src/Shell/Color.cpp
# Headers
cincludedir = $(includedir)/Aurora
cinclude_HEADERS = ../include/Aurora/Aurora.h \
                   ../include/Aurora/GUIWindow.h \
                   ../include/Aurora/InfoRAM.h \
                   ../include/Aurora/ShellLog.h \
                   ../include/Aurora/Application.h \
                   ../include/Aurora/Typedef.h \
                   ../include/Aurora/Macros.h \
                   ../include/Aurora/GUIApplication.h \
                   ../include/Aurora/GUILabel.h \
                   ../include/Aurora/ShellColor.h