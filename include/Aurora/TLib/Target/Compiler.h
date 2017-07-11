// TODO: Include Compiler Targets ( https://sourceforge.net/p/predef/wiki/Compilers/ )

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#if defined(__GNUG__) || (defined(__GNUC__) && defined(__cplusplus))
	#ifndef AURORA_TARGET_COMPILER_GNU
		#define AURORA_TARGET_COMPILER_GNU
	#endif
	#define AURORA_TARGET_COMPILER_GNU_CXX
	#define AURORA_TARGET_CXX
	#ifdef __GNUC__
		#define AURORA_TARGET_CC
	#endif
#elif defined(__GNUC__)
	#ifndef AURORA_TARGET_COMPILER_GNU
		#define AURORA_TARGET_COMPILER_GNU
	#endif
	#define AURORA_TARGET_COMPILER_GNU_CC
	#define AURORA_TARGET_CXX
	#define AURORA_TARGET_CC
#elif defined(__CC_ARM)
	#define AURORA_TARGET_COMPILER_ARM
#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
	#define AURORA_TARGET_COMPILER_BORLAND
#elif defined(__clang__)
	#define AURORA_TARGET_COMPILER_CLANG
#elif defined(__COMO__)
	#define AURORA_TARGET_COMPILER_COMEAU
#elif defined(__DECC)
	#define AURORA_TARGET_COMPILER_COMPAQ_CC
	#define AURORA_TARGET_CC
#elif defined(__DECCXX)
	#define AURORA_TARGET_COMPILER_COMPAQ_CXX
#elif defined(__convexc__)
	#define AURORA_TARGET_COMPILER_CONVEXC
	#define AURORA_TARGET_CC
#elif defined(_MSC_VER)
	#define AURORA_TARGET_COMPILER_MICROSOFT
	#define AURORA_TARGET_CXX
	#define AURORA_TARGET_CC
#elif defined(__MINGW32__)
	#define AURORA_TARGET_COMPILER_MINGW
	#define AURORA_TARGET_CXX
	#define AURORA_TARGET_CC
#endif
