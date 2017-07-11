//TODO: Need to be documented and structured !!!

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/TLib/Target/Compiler.h>

#ifdef __cplusplus
	#ifndef AURORA_TARGET_CXX
		#define AURORA_TARGET_CXX
	#endif
	#ifdef AURORA_TARGET_CC
		#undef AURORA_TARGET_CC
	#endif
#else
	#ifndef AURORA_TARGET_CC
		#define AURORA_TARGET_CC
	#endif
	#ifdef AURORA_TARGET_CXX
		#undef AURORA_TARGET_CXX
	#endif
#endif
