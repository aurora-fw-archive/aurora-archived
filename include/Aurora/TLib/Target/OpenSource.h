#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_MODULE_CORE_TLIB
	#define AURORA_MODULE_CORE_TLIB
#endif /// AURORA_MODULE_CORE_TLIB

#include <Aurora/TLib/Target/Platform.h>
#include <Aurora/TLib/Target/Kernel.h>
#include <Aurora/TLib/Target/Environment.h>

#ifdef AURORA_TARGET_PLATFORM_ANDROID
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
    #endif
#elif defined(AURORA_TARGET_CYGWIN)
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
    #endif
#endif

#ifdef AURORA_TARGET_KERNEL_LINUX
    #ifndef AURORA_TARGET_IS_OPENSOURCE
        #define AURORA_TARGET_IS_OPENSOURCE
    #endif
#elif defined(AURORA_TARGET_FREEBSD)
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(AURORA_TARGET_OPENBSD)
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(AURORA_TARGET_NETBSD)
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(AURORA_TARGET_DRAGONFLY)
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#endif
