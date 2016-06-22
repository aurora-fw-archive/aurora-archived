// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: include/Aurora/Lib/Type.h
// Contains: Types Declaration

#ifndef INCLUDE_H_AURORA_LIB_TYPE
#define INCLUDE_H_AURORA_LIB_TYPE   1

#pragma once

#include <Aurora/Core/Aurora.h>
#include <Aurora/Core/Target.h>

#ifdef AURORA_TARGET_CXX
#include <cstdint>
#else
#include <stdint.h>
#endif

#ifdef AURORA_TARGET_COMPILER_MICROSOFT
        // Signed
        typedef __int8 ArInt8_t;
        typedef __int16 ArInt16_t;
        typedef __int32 ArInt32_t;
        typedef __int64 ArInt64_t;

        // Unsigned
        typedef unsigned __int8  ArUInt8_t;
        typedef unsigned __int16 ArUInt16_t;
        typedef unsigned __int32 ArUInt32_t;
        typedef unsigned __int64 ArUInt64_t;
#else
// Signed
typedef int8_t ArInt8_t;
typedef int16_t ArInt16_t;
typedef int32_t ArInt32_t;
typedef int64_t ArInt64_t;

// Unsigned
typedef uint8_t ArUInt8_t;
typedef uint16_t ArUInt16_t;
typedef uint32_t ArUInt32_t;
typedef uint64_t ArUInt64_t;
#endif

typedef size_t ArSize_t;
typedef wchar_t ArWChar_t;

typedef int ArInt;
typedef short int ArShort_t;
typedef long int ArLong_t;
typedef char ArChar;
typedef float ArFloat;
typedef double ArDouble;
typedef long double ArLDouble;
typedef bool ArBool;
typedef unsigned char ArByte;

// Unsigned
typedef unsigned int ArUInt_t;
typedef unsigned char ArUChar_t;
typedef unsigned short int ArUShort_t;
typedef unsigned long int ArULong_t;

typedef void ArSlot_t;

#define AURORA_INT_MIN          (-2147483647-1)
#define AURORA_INT8_MIN		(-128)
#define AURORA_INT16_MIN	(-32767-1)
#define AURORA_INT32_MIN	(-2147483647-1)
#define AURORA_INT64_MIN	(-9223372036854775807-1)

#define AURORA_INT_MAX          (2147483647)
#define AURORA_INT8_MAX		(127)
#define AURORA_INT16_MAX	(32767)
#define AURORA_INT32_MAX	(2147483647)
#define AURORA_INT64_MAX	(9223372036854775807)

#define AURORA_UINT8_MAX	(255)
#define AURORA_UINT16_MAX	(65535)
#define AURORA_UINT32_MAX	(4294967295)
#define AURORA_UINT64_MAX	(18446744073709551615)


#endif // INCLUDE_H_AURORA_LIB_TYPE