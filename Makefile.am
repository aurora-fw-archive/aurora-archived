# Process this file with automake to produce Makefile.in
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

# C++ Flags
AM_CXXFLAGS = -Wall -Wextra -std=c++14 -I../include/
AM_CFLAGS = -Wall -Wno-unknown-pragmas -Wextra -std=c11 -I../include/

# Library Modules
lib_LTLIBRARIES = $(top_builddir)/../bin/libaurora-core-tlib.la \
                  $(top_builddir)/../bin/libaurora-core.la \
                  $(top_builddir)/../bin/libaurora-ai.la \
                  $(top_builddir)/../bin/libaurora-audio.la \
                  $(top_builddir)/../bin/libaurora-cli-core.la \
                  $(top_builddir)/../bin/libaurora-cli-asciiengine.la \
                  $(top_builddir)/../bin/libaurora-cli.la \
                  $(top_builddir)/../bin/libaurora-crypto.la \
                  $(top_builddir)/../bin/libaurora-gengine-core.la \
                  $(top_builddir)/../bin/libaurora-gengine.la \
                  $(top_builddir)/../bin/libaurora-gui.la \
                  $(top_builddir)/../bin/libaurora-image.la \
                  $(top_builddir)/../bin/libaurora-io.la \
                  $(top_builddir)/../bin/libaurora-math-parser.la \
                  $(top_builddir)/../bin/libaurora-math-core.la \
                  $(top_builddir)/../bin/libaurora-math.la \
                  $(top_builddir)/../bin/libaurora-misc.la \
                  $(top_builddir)/../bin/libaurora-netsocks.la \
                  $(top_builddir)/../bin/libaurora-parse-xml.la \
                  $(top_builddir)/../bin/libaurora-parse-json.la \
                  $(top_builddir)/../bin/libaurora-parse-yaml.la \
                  $(top_builddir)/../bin/libaurora-parse.la \
                  $(top_builddir)/../bin/libaurora-soc-android.la \
                  $(top_builddir)/../bin/libaurora-soc-arm.la \
                  $(top_builddir)/../bin/libaurora-soc-avr-core.la \
                  $(top_builddir)/../bin/libaurora-soc-avr-arduino.la \
                  $(top_builddir)/../bin/libaurora-soc-avr.la \
                  $(top_builddir)/../bin/libaurora-soc.la \
                  $(top_builddir)/../bin/libaurora.la

# Libraries Internal Dependencies
__top_builddir_____bin_libaurora_core_la_LIBADD = $(top_builddir)/../bin/libaurora-core-tlib.la
__top_builddir_____bin_libaurora_ai_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_audio_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_cli_core_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_cli_asciiengine_la_LIBADD = $(top_builddir)/../bin/libaurora-cli-core.la
__top_builddir_____bin_libaurora_cli_la_LIBADD = $(top_builddir)/../bin/libaurora-cli-asciiengine.la
__top_builddir_____bin_libaurora_crypto_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_gengine_core_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_gengine_la_LIBADD = $(top_builddir)/../bin/libaurora-gengine-core.la
__top_builddir_____bin_libaurora_gui_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_image_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_io_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_math_parser_la_LIBADD = $(top_builddir)/../bin/libaurora-math-core.la
__top_builddir_____bin_libaurora_math_core_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_math_la_LIBADD = $(top_builddir)/../bin/libaurora-math-parser.la
__top_builddir_____bin_libaurora_misc_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_netsocks_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_parse_xml_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_parse_json_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_parse_yaml_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_parse_la_LIBADD = $(top_builddir)/../bin/libaurora-parse-xml.la \
                                                   $(top_builddir)/../bin/libaurora-parse-json.la \
                                                   $(top_builddir)/../bin/libaurora-parse-yaml.la
__top_builddir_____bin_libaurora_soc_android_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_soc_arm_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_soc_avr_core_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la
__top_builddir_____bin_libaurora_soc_avr_arduino_la_LIBADD = $(top_builddir)/../bin/libaurora-soc-avr-core.la
__top_builddir_____bin_libaurora_soc_avr_la_LIBADD = $(top_builddir)/../bin/libaurora-soc-avr-arduino.la
__top_builddir_____bin_libaurora_soc_la_LIBADD = $(top_builddir)/../bin/libaurora-soc-android.la \
                                                 $(top_builddir)/../bin/libaurora-soc-arm.la \
                                                 $(top_builddir)/../bin/libaurora-soc-avr.la
__top_builddir_____bin_libaurora_la_LIBADD = $(top_builddir)/../bin/libaurora-core.la \
                                             $(top_builddir)/../bin/libaurora-ai.la \
                                             $(top_builddir)/../bin/libaurora-audio.la \
                                             $(top_builddir)/../bin/libaurora-cli.la \
                                             $(top_builddir)/../bin/libaurora-crypto.la \
                                             $(top_builddir)/../bin/libaurora-gengine.la \
                                             $(top_builddir)/../bin/libaurora-gui.la \
                                             $(top_builddir)/../bin/libaurora-image.la \
                                             $(top_builddir)/../bin/libaurora-io.la \
                                             $(top_builddir)/../bin/libaurora-math.la \
                                             $(top_builddir)/../bin/libaurora-misc.la \
                                             $(top_builddir)/../bin/libaurora-netsocks.la \
                                             $(top_builddir)/../bin/libaurora-parse.la \
                                             $(top_builddir)/../bin/libaurora-soc.la

# Libraries External Dependencies
__top_builddir_____bin_libaurora_gui_la_CXXFLAGS = $(AM_CXXFLAGS) `pkg-config --cflags --libs gtk+-3.0`
__top_builddir_____bin_libaurora_gui_la_CFLAGS = $(AM_CFLAGS) `pkg-config --cflags --libs gtk+-3.0`

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

__top_builddir_____bin_libaurora_c_la_SOURCES = ../src/Lib/Memory.c \
                                               ../src/Lib/String2.c

# Headers
rootincludedir = $(includedir)/Aurora
rootinclude_HEADERS = ../include/Aurora/Aurora.h \
                   ../include/Aurora/GEngine.h

# AI Headers
aiincludedir = $(includedir)/Aurora/AI
#aiinclude_HEADERS =

# Audio Headers
audioincludedir = $(includedir)/Aurora/Audio
#audioinclude_HEADERS =

# CLI Headers
    # CLI Core Headers
    clicoreincludedir = $(includedir)/Aurora/CLI
    clicoreinclude_HEADERS = ../include/Aurora/CLI/ASCII.h \
                             ../include/Aurora/CLI/Color.h \
                             ../include/Aurora/CLI/Info.h \
                             ../include/Aurora/CLI/Input.h \
                             ../include/Aurora/CLI/Log.h \
                             ../include/Aurora/CLI/Output.h

    # CLI ASCII Engine Headers
    cliasciiincludedir = $(includedir)/Aurora/CLI/ASCII
    #cliasciiinclude_HEADERS =

# Core Headers
coreincludedir = $(includedir)/Aurora/Core
coreinclude_HEADERS = ../include/Aurora/Core/Application.h \
                      ../include/Aurora/Core/Aurora.h \
                      ../include/Aurora/Core/Debug.h


# Cross Headers
    # Cross/System Headers
    crosssystemincludedir = $(includedir)/Aurora/Cross/System
    crosssysteminclude_HEADERS = ../include/Aurora/Cross/System/IO.h

    # Cross/Video Headers
    crossvideoincludedir = $(includedir)/Aurora/Cross/Video
    crossvideoinclude_HEADERS = ../include/Aurora/Cross/Video/VGA.h

# Crypto Headers
cryptoincludedir = $(includedir)/Aurora/Crypto
cryptoinclude_HEADERS = ../include/Aurora/Crypto/AES.h

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
