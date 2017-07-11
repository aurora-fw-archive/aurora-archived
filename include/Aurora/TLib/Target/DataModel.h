/// <Aurora/Lib/Target/DataModels.h> -*- C/C++ Header -*-
/// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
/// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
/// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
///  Copyright (c) 2016 - Luís Ferreira. All right reserved
///  More information in: https://github.com/ljmf00/ (Github Page)

/// This file is part of the Aurora Framework. This framework is free
/// software; you can redistribute it and/or modify it under the
/// terms of the GNU Lesser General Public License, v3.

/* @module aurora-core-tlib
** @title Targets - Data Models
** @brief This header is for data model detection.
** @source https://sourceforge.net/p/predef/wiki/DataModels/
** @TODO: Nothing yet.
*/

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

// Data type 	LP32 	ILP32 	LP64 	LLP64 	ILP64 	SILP64
// char 		8 		8 		8 		8 		8 		8
// short 		16 		16 		16 		16 		16 		64
// int 			16 		32 		32 		32 		64 		64
// long 		32 		32 		64 		32 		64 		64
// long long 	64 		64 		64 		64
// pointer 		32 		32 		64 		64 		64 		64

// _ILP32 		Defined by HP aCC and Sun Studio
// __ILP32__ 	Defined by GNU C
#if defined(__ILP32__) || defined(_ILP32)
	#define AURORA_TARGET_DATAMODEL_ILP32

// _LP64 		Defined by HP aCC and Sun Studio
// __LP64__ 	Defined by GNU C
#elif defined(__LP64__) || defined(_LP64)
	#define AURORA_TARGET_DATAMODEL_LP64
#endif
