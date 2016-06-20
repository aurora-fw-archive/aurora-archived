// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: include/Aurora/Lib/Type.h
// Contains: Types Declaration

#ifndef INCLUDE_H_AURORA_LIB_TYPE
#define INCLUDE_H_AURORA_LIB_TYPE   1

#include <Aurora/Core/Aurora.h>
#include <Aurora/Lib/Target.h>

#if defined(AURORA_TARGET_CPU_86_64) && !defined(AURORA_TARGET_CPU_ILP32)
    #define __AURORA_WORDSIZE   64
#else
    #define __AURORA_WORDSIZE   32
#endif

#ifdef AURORA_TARGET_COMPILER_MICROSOFT
    #ifndef __AURORA_INT_TYPE
        #define __AURORA_INT_TYPE

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
    #endif
    #ifndef __AURORA_INT_MACRO
        #define __AURORA_INT_MACRO

        #define AURORA_INT8_MIN		(-128)
        #define AURORA_INT16_MIN	(-32767-1)
        #define AURORA_INT32_MIN	(-2147483647-1)
        #define AURORA_INT64_MIN	(-9223372036854775807-1)

        #define AURORA_INT8_MAX		(127)
        #define AURORA_INT16_MAX	(32767)
        #define AURORA_INT32_MAX	(2147483647)
        #define AURORA_INT64_MAX	(9223372036854775807)

        #define AURORA_UINT8_MAX	(255)
        #define AURORA_UINT16_MAX	(65535)
        #define AURORA_UINT32_MAX	(4294967295U)
        #define AURORA_UINT64_MAX	(18446744073709551615)
    #endif
#else
    #ifndef __AURORA_INT_TYPE
        #define __AURORA_INT_TYPE

        // Signed
        typedef signed char ArInt8_t;
        typedef signed short int ArInt16_t;
        typedef signed int ArInt32_t;
        #if __AURORA_WORDSIZE == 64
            typedef signed long int ArInt64_t;
        #else
            #ifdef AURORA_TARGET_COMPILER_GNU
                __extension__
            #elif defined(AURORA_TARGET_COMPILER_MINGW)
                _MINGW_EXTENSION
            #else
            __extension__
            #endif
            typedef signed long long int ArInt64_t;
        #endif

        // Unsigned
        typedef unsigned char ArUInt8_t;
        typedef unsigned short int ArUInt16_t;
        typedef unsigned int ArUInt32_t;
        #if __AURORA_WORDSIZE == 64
            typedef unsigned long int ArUInt64_t;
        #else
            #ifdef AURORA_TARGET_COMPILER_GNU
                __extension__
            #elif defined(AURORA_TARGET_COMPILER_MINGW)
                _MINGW_EXTENSION
            #else
            __extension__
            #endif
            typedef unsigned long long int ArUInt64_t;
        #endif
    #endif
    #ifndef __AURORA_INT_MACRO
        #define __AURORA_INT_MACRO
        #if __AURORA_WORDSIZE == 64
            #define __AURORA_INT64_C(c)     c ## L
            #define __AURORA_UINT64_C(c)    c ## UL
        #else
            #define __AURORA_INT64_C(c)     c ## LL
            #define __AURORA_UINT64_C(c)    c ## ULL
        #endif

        #define AURORA_INT8_MIN		(-128)
        #define AURORA_INT16_MIN	(-32767-1)
        #define AURORA_INT32_MIN	(-2147483647-1)
        #define AURORA_INT64_MIN	(-__AURORA_INT64_C(9223372036854775807)-1)

        #define AURORA_INT8_MAX		(127)
        #define AURORA_INT16_MAX	(32767)
        #define AURORA_INT32_MAX	(2147483647)
        #define AURORA_INT64_MAX	(__AURORA_INT64_C(9223372036854775807))

        #define AURORA_UINT8_MAX	(255)
        #define AURORA_UINT16_MAX	(65535)
        #define AURORA_UINT32_MAX	(4294967295U)
        #define AURORA_UINT64_MAX	(__AURORA_UINT64_C(18446744073709551615))
    #endif
#endif

#ifndef __AURORA_SIZE_TYPE
    #define __AURORA_SIZE_TYPE
    #if __AURORA_WORDSIZE == 64
        typedef long unsigned int ArSize_t;
    #elif __AURORA_WORDSIZE == 32
        #ifdef AURORA_TARGET_COMPILER_GNU
            __extension__
        #elif defined(AURORA_TARGET_COMPILER_MINGW)
            _MINGW_EXTENSION
        #else
            __extension__
        #endif
        typedef long long unsigned int ArSize_t;
    #endif
#endif

#ifndef __AURORA_WCHAR_TYPE
    #define __AURORA_WCHAR_TYPE
    typedef int ArWChar_t;
#endif


typedef int ArInt;
typedef char ArChar;
typedef float ArFloat;
typedef double ArDouble;
typedef unsigned char ArByte;

// Unsigned
typedef unsigned int ArUInt_t;
typedef unsigned char ArUChar_t;
typedef unsigned short int ArUShort_t;
typedef unsigned long int ArULong_t;

typedef void ArSlot_t;

#endif // INCLUDE_H_AURORA_LIB_TYPE