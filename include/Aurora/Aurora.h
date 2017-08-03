// <Aurora/Aurora.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* @contains: Core Header Group */

#ifndef INCLUDE_H_AURORA_H_INCLUDE
#define INCLUDE_H_AURORA_H_INCLUDE

/// Safe include
#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

// Core
#include <Aurora/Core/Application.h>
#include <Aurora/Core/Debug.h>

// Crypto
#include <Aurora/Crypto/AES.h>

// GUI
#include <Aurora/GUI/Window.h>
#include <Aurora/GUI/Label.h>
#include <Aurora/GUI/Button.h>
#include <Aurora/GUI/Layout.h>
#include <Aurora/GUI/Application.h>

// Shell
#include <Aurora/CLI/Log.h>
#include <Aurora/CLI/Color.h>
#include <Aurora/CLI/Output.h>
#include <Aurora/CLI/Input.h>

// Lib
#include <Aurora/TLib/Target.h>
#include <Aurora/TLib/Type.h>
#include <Aurora/TLib/IOStream.h>
#include <Aurora/TLib/Endian.h>
#include <Aurora/TLib/String.h>

// Information
#include <Aurora/Info/RAM.h>
#include <Aurora/Info/OS.h>

//GEngine
#include <Aurora/GEngine/Application.h>
#include <Aurora/GEngine/Window.h>
#include <Aurora/GEngine/API.h>
#include <Aurora/GEngine/OpenGL.h>
#include <Aurora/GEngine/Vulkan.h>
#include <Aurora/GEngine/Direct3D.h>

//#include <Aurora/Info/GPU.h>
//#include <Aurora/Info/CPU.h>
//#include <Aurora/Info/System.h>

// Headers for cross-compiler

//#include <Aurora/Cross/System/IO.h>
//#include <Aurora/Cross/Video/VGA.h>


#endif // INCLUDE_H_AURORA_H_INCLUDE
