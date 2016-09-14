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

#include <Aurora/Core/Aurora.h>
#include <Aurora/Lib/Target.h>
#include <Aurora/Lib/Type.h>

#ifdef AURORA_TARGET_CXX
	extern "C" {
#endif
		extern void *memcpy(void *dst, const void *src, size_t n);
		extern void *memmove(void *dst, const void *src, size_t n);
		extern int memcmp(const void *cs, const void *ct, size_t n);
		extern void *memset(void *s, int c, size_t n);
#ifdef AURORA_TARGET_CXX
	}
#endif