# Process this file with automake to produce Makefile.in
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

AM_CXXFLAGS = -Wall -Wextra -std=c++14 -lX11 -lGL -lGLU -lglut -I../include/
lib_LTLIBRARIES = ../bin/libaurora.la
libaurora_la_SOURCES = ../src/GUI/Event.cpp \
                       ../src/GUI/Window.cpp \
                       ../src/Info/RAM.cpp \
                       ../src/Shell/Log.cpp \
                       ../src/Aurora/Application.cpp

# Headers
cincludedir = $(includedir)/Aurora
cinclude_HEADERS = ../include/Aurora/GUIEvent.h \
                   ../include/Aurora/GUIWindow.h \
                   ../include/Aurora/InfoRAM.h \
                   ../include/Aurora/ShellLog.h \
                   ../include/Aurora/Application.h \
                   ../include/Aurora/Typedef.h \
                   ../include/Aurora/Macros.h