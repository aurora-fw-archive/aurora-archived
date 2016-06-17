// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_TYPEDEF
#define INCLUDE_H_AURORA_TYPEDEF

#include <Aurora/Core/Targets.h>
#include <Aurora/Core/Aurora.h>

#ifdef AURORA_TARGET_CXX
#include <iostream>
#include <string>

#include <cwchar>
#include <cstdint>

typedef std::string arstring_t;
typedef std::wstring arwstring_t;
#elif defined(AURORA_TARGET_CC)
#include <wchar.h>
#include <cstdint.h>

typedef char **ar_string_t;
typedef wchar_t **ar_wstring_t;
#endif

// Custom types
typedef void arslot_t;
typedef int arflags_t;

typedef char archar_t;
typedef wchar_t arwchar_t;

// For Bytes
typedef unsigned char arbyte_t;

#endif // INCLUDE_H_AURORA_TYPEDEF