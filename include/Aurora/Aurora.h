// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_H_INCLUDE
#define _AURORA_H_INCLUDE

#pragma once

// Core
#include <Aurora/Core/Typedef.h>
#include <Aurora/Core/Application.h>
#include <Aurora/Core/Macros.h>

// GUI
#include <Aurora/GUI/Window.h>
#include <Aurora/GUI/Application.h>

// Shell
#include <Aurora/Shell/Log.h>
#include <Aurora/Shell/ColorType.h>
#include <Aurora/Shell/TextStyle.h>
#include <Aurora/Shell/Color.h>

// Information

#include <Aurora/Info/RAM.h>
//#include <Aurora/Info/OS.h>
//#include <Aurora/Info/GPU.h>
//#include <Aurora/Info/CPU.h>
//#include <Aurora/Info/System.h>

// Headers for cross-compiler
#if !defined(__unix__) && !defined(__unix) &&   \
    !defined(_WIN32) && !defined(__linux__) &&  \
    !defined(__APPLE__) && !defined(__MACH__)
//#include <Aurora/Cross/System/IO.h>
//#include <Aurora/Cross/Video/VGA.h>
#endif

#endif // _AURORA_H_INCLUDE