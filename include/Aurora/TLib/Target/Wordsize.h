//TODO: Need to be documented and structured !!!

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef INCLUDE_H_AURORA_LIB_TARGET_WORDSIZE
#define INCLUDE_H_AURORA_LIB_TARGET_WORDSIZE 1

#include <Aurora/TLib/Target/DataModel.h>
#include <Aurora/TLib/Target/Architecture.h>

#if defined(AURORA_TARGET_CPUARCH_86_64) && !defined(AURORA_TARGET_DATAMODEL_ILP32)
	#define AURORA_TARGET_WORDSIZE   64
#else
	#define AURORA_TARGET_WORDSIZE   32
#endif

#endif /// INCLUDE_H_AURORA_LIB_TARGET_WORDSIZE
