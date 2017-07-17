#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef INCLUDE_H_AURORA_GENERAL_COMMON
#define INCLUDE_H_AURORA_GENERAL_COMMON

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#include <Aurora/TLib/Target/Platform.h>

#ifdef AURORA_TARGET_PLATFORM_WINDOWS
	#ifdef AURORA_IS_COMPILING
		#define AURORA_PREFIX __declspec(dllexport)
	#else
		#define AURORA_PREFIX __declspec(dllimport)
	#endif //AURORA_IS_COMPILING
#else
	#define AURORA_PREFIX
#endif //AURORA_TARGET_PLATFORM_WINDOWS

#endif // INCLUDE_H_AURORA_GENERAL_COMMON
