/// <Aurora/Lib/Target.h> -*- C/C++ Header -*-
/// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
/// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
/// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
///  Copyright (c) 2016 - Luís Ferreira. All right reserved
///  More information in: https://github.com/ljmf00/ (Github Page)

/// This file is part of the Aurora Framework. This framework is free
/// software; you can redistribute it and/or modify it under the
/// terms of the GNU Lesser General Public License, v3.

/* @module aurora-core-tlib
** @title Targets
** @brief This is the main header file for target detections.
** @TODO: Need to be well documented!!!
** @TODO: Need to verify and test ALL targets !!! (very long process)
** @TODO: Implement other macros ( https://sourceforge.net/p/predef/wiki/Home/ )
*/

#ifndef AURORA_MODULE_CORE_TLIB
	#define AURORA_MODULE_CORE_TLIB
#endif /// AURORA_MODULE_CORE_TLIB

/// Safe include
#include <Aurora/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef INCLUDE_H_AURORA_LIB_TARGET
#define INCLUDE_H_AURORA_LIB_TARGET	1

// CPU Architecture Targets
#include <Aurora/Lib/Target/Architecture.h>
// C or C++ Languages detection
#include <Aurora/Lib/Target/CCPlusPlus.h>
// Compiler Targets (Include detection and version)
#include <Aurora/Lib/Target/Compiler.h>
// Data Models
#include <Aurora/Lib/Target/DataModel.h>
// Others Targets detections
#include <Aurora/Lib/Target/Misc.h>
// Open Source Target detection
#include <Aurora/Lib/Target/OpenSource.h>
// Platform detection
#include <Aurora/Lib/Target/Platform.h>
// Standards detections
#include <Aurora/Lib/Target/Standards.h>
// Data Type size - Word size for a specific target
#include <Aurora/Lib/Target/Wordsize.h>

#endif /// INCLUDE_H_AURORA_LIB_TARGET
