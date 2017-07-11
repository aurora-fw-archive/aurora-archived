#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_MODULE_CORE_TLIB
	#define AURORA_MODULE_CORE_TLIB
#endif /// AURORA_MODULE_CORE_TLIB

#if defined(__ppc__) || defined(__powerpc__) || defined(__PPC__) || defined(__POWERPC__)
	#define AURORA_TARGET_CPUARCH_POWERPC
	#define AURORA_TARGET_CPUARCH_POWERPC_32
	#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__)
		#define AURORA_TARGET_CPUARCH_POWERPC_64
	#endif
#endif

#if defined(__i386) || defined(_M_IX86) || defined(__i386__) || (defined(__MWERKS__) && defined(__INTEL__))
	#define AURORA_TARGET_CPUARCH_INTELX86
#elif defined(__x86_64__) || defined(_M_X64) || defined(__amd64__) || defined(__amd64) || defined(_M_AMD64)
	#define AURORA_TARGET_CPUARCH_AMD64
#elif defined(__arm__)
	#define AURORA_TARGET_CPUARCH_ARM
#endif

#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
	#define AURORA_TARGET_CPUARCH_ITANIUM
#elif defined(__sparc)
	#define AURORA_TARGET_CPUARCH_SPARC
#endif
