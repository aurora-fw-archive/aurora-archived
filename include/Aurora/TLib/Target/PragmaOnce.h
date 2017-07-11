/// <Aurora/Lib/Target/PragmaOnce.h> -*- C/C++ Header -*-
/// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
/// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
/// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
///  Copyright (c) 2016 - Luís Ferreira. All right reserved
///  More information in: https://github.com/ljmf00/ (Github Page)

/// This file is part of the Aurora Framework. This framework is free
/// software; you can redistribute it and/or modify it under the
/// terms of the GNU Lesser General Public License, v3.

/* @module aurora-core-tlib
** @title Targets - '#pragma once' support
** @brief This header is for detection of pragma once
**        support on a specific target.
** @TODO: Current compilers need to be defined by
**        AURORA_TARGET predef's.
*/

#ifndef INCLUDE_H_AURORA_LIB_TARGET_PRAGMAONCE
#define INCLUDE_H_AURORA_LIB_TARGET_PRAGMAONCE 1

#include <Aurora/TLib/Target/Compiler.h>

// Oracle Developer Studio C/C++ (12.5 or later)
#if (defined(__SUNPRO_C)&&(__SUNPRO_C>=0x5140))||(defined(__SUNPRO_CC)&&(__SUNPRO_CC>=0x5140))
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// MSVC
#elif defined(_MSC_VER)&&(_MSC_VER>=1020)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// clang
#elif defined(__clang__)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// comeau
#elif defined(__COMO__)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// C++Builder (XE3 or greater)
#elif defined(__CODEGEARC__)&&(__CODEGEARC__ >=650)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// Digital Mars
#elif defined(__DMC__)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// GCC
#elif defined(__GNUC__)&&((__GNUC__ >3)||(defined(__GNUC_MINOR__)&&(__GNUC__ ==3)&&(__GNUC_MINOR__ >=4)))
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// HP aC++ (A.06.12)
#elif defined(__HP_aCC)&&(__HP_aCC >=61200)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// IBM
#elif defined(__xlC__)&&((__xlC__ >1301)||((__xlC__ ==1301)&&(__xlC_ver__ >0100)))
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// Intel
#elif defined(__INTEL_COMPILER)||defined(__ICC)||defined(__ECC)||defined(__ICL)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// Pelles C
#elif defined(__POCC__)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// ARM compiler
#elif defined(__CC_ARM)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// IAR C/C++
#elif defined(__IAR_SYSTEMS_ICC__)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
// Portland Group C/C++
#elif defined(__PGI)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 0
#endif

#endif /// INCLUDE_H_AURORA_LIB_TARGET_PRAGMAONCE
