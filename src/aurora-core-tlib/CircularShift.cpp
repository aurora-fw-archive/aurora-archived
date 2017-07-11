// "src/Lib/CircularShift.cpp" -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/*
** @contains: Circular Shift operations Source file
*/

#include <Aurora/TLib/CircularShift.h>

#ifdef AURORA_TARGET_CXX
	namespace
	{
#endif
	inline uint32_t rotl32 (uint32_t value, unsigned int count)
	{
		const unsigned int mask = (CHAR_BIT*sizeof(value)-1);
		count &= mask;
		return (value<<count) | (value>>( (-count) & mask ));
	}
	inline uint32_t rotr32 (uint32_t value, unsigned int count)
	{
		const unsigned int mask = (CHAR_BIT*sizeof(value)-1);
		count &= mask;
		return (value>>count) | (value<<( (-count) & mask ));
	}
	inline uint64_t rotl64 (uint64_t value, unsigned int count)
	{
		const unsigned int mask = (CHAR_BIT*sizeof(value)-1);
		count &= mask;
		return (value>>count) | (value<<( (-count) & mask ));
	}
	inline uint64_t rotr64 (uint64_t value, unsigned int count)
	{
		const unsigned int mask = (CHAR_BIT*sizeof(value)-1);
		count &= mask;
		return (value>>count) | (value<<( (-count) & mask ));
	}

#ifdef AURORA_TARGET_CXX
	}
#endif
