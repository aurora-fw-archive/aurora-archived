// <Aurora/Lib/Memory.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* Contains: Memory Managment function */

/// Safe include
#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#ifndef AURORA_MODULE_CORE_TLIB
	#define AURORA_MODULE_CORE_TLIB
#endif /// AURORA_MODULE_CORE_TLIB

#include <Aurora/TLib/Target/CCPlusPlus.h>
#include <Aurora/TLib/Type.h>

#ifdef AURORA_TARGET_CXX
	extern "C" {
#endif
		void *memcpy(void *dst, const void *src, size_t n);
		void *memmove(void *dst, const void *src, size_t n);
		int memcmp(const void *cs, const void *ct, size_t n);
		void *memset(void *s, int c, size_t n);
#ifdef AURORA_TARGET_CXX
	}
#endif
