// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: include/Aurora/Lib/Target.h
// Contains: Targets for Operation System / Kernel / Platform Detection

#ifndef INCLUDE_H_AURORA_LIB_TARGET
#define INCLUDE_H_AURORA_LIB_TARGET 1

#pragma once

#include <Aurora/Core/Aurora.h>

// TODO: Implement this macros ( https://sourceforge.net/p/predef/wiki/OperatingSystems/ )
//       Needs to test all macros ( Windows and Apple platforms and ARM and PowerPC Architectures)

#ifdef _WIN16
	#define AURORA_TARGET_WINDOWS
	#define AURORA_TARGET_WINDOWS_16
#elif defined(_WIN32)
	#define AURORA_TARGET_WINDOWS
	#define AURORA_TARGET_WINDOWS_32
	#ifdef _WIN64
		#define AURORA_TARGET_WINDOWS_86_64
	#endif
#elif __APPLE__
	#define AURORA_TARGET_APPLE
	#if defined(__APPLE_CPP__) || defined(__APPLE_CC__) || defined(__MACOS_CLASSIC__)
		#if (defined(__APPLE__) && defined(__MACH__)) || defined(macintosh) || defined(Macintosh)
			#define AURORA_TARGET_APPLE_MAC
		#endif
		#if defined(__GNUC__)
			#define TARGET_OS_EMBEDDED          @CONFIG_EMBEDDED@
			#define TARGET_OS_IPHONE            @CONFIG_IPHONE@
			#define TARGET_IPHONE_SIMULATOR     @CONFIG_IPHONE_SIMULATOR@
			#if TARGET_IPHONE_SIMULATOR
				#define AURORA_TARGET_APPLE_IPHONE_SIMULATOR
			#elif TARGET_OS_IPHONE
				#define AURORA_TARGET_APPLE_IPHONE
			#elif TARGET_OS_EMBEDDED
				#define AURORA_TARGET_APPLE_EMBEDDED
			#endif
		#endif
	#endif
#elif defined(__linux__) || defined(__linux) || defined(linux)
	#define AURORA_TARGET_LINUX
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
	#ifdef __gnu_linux__
		#define AURORA_TARGET_GNU_LINUX
		#ifndef AURORA_TARGET_IS_OPENSOURCE
			#define AURORA_TARGET_IS_OPENSOURCE
		#endif
	#endif
#endif

#if defined(__unix__) || defined(__unix) || defined(unix)
	#define AURORA_TARGET_UNIX
#endif

#ifdef __ANDROID__
	#define AURORA_TARGET_ANDROID
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif __CYGWIN__
	#define AURORA_TARGET_CYGWIN
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	#define AURORA_TARGET_FREEBSD
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(__OpenBSD__)
	#define AURORA_TARGET_OPENBSD
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(__NetBSD__)
	#define AURORA_TARGET_NETBSD
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#elif defined(__DragonFly__)
	#define AURORA_TARGET_DRAGONFLY
	#ifndef AURORA_TARGET_IS_OPENSOURCE
		#define AURORA_TARGET_IS_OPENSOURCE
	#endif
#endif

#if defined(__ppc__) || defined(__powerpc__) || defined(__PPC__) || defined(__POWERPC__)
	#define AURORA_TARGET_POWERPC
	#define AURORA_TARGET_POWERPC_32
	#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__)
		#define AURORA_TARGET_POWERPC_64
	#endif
#endif

#if defined(__i386) || defined(_M_IX86) || defined(__i386__) || (defined(__MWERKS__) && defined(__INTEL__))
	#define AURORA_TARGET_CPU_I386
#elif defined(__x86_64__) || defined(_M_X64) || defined(__amd64__) || defined(__amd64) || defined(_M_AMD64)
	#define AURORA_TARGET_CPU_86_64
#elif defined(__arm__)
	#define AURORA_TARGET_CPU_ARM
#endif

#ifdef __ILP32__
	#define AURORA_TARGET_CPU_ILP32
#endif

#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
	#define AURORA_TARGET_CPU_ITANIUM
#elif defined(__sparc)
	#define AURORA_TARGET_CPU_SPARC
#endif

// TODO: Include Compiler Targets ( https://sourceforge.net/p/predef/wiki/Compilers/ )

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

#ifdef __ELF__
	#define AURORA_TARGET_ELF
#endif

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

#ifndef __AURORA_WORDSIZE
	#if defined(AURORA_TARGET_CPU_86_64) && !defined(AURORA_TARGET_CPU_ILP32)
		#define AURORA_WORDSIZE   64
	#else
		#define AURORA_WORDSIZE   32
	#endif
#endif

#ifdef __STRICT_ANSI__
	#define AURORA_TARGET_STRICT_ANSI
#endif

/*checks for pragma once support*/
#if (defined(__SUNPRO_C)&&(__SUNPRO_C>=0x5140))||(defined(__SUNPRO_CC)&&(__SUNPRO_CC>=0x5140))
	//Oracle Developer Studio C/C++ (12.5 or later)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(_MSC_VER)&&(_MSC_VER>=1020)	//MSVC
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__clang__)		//clang
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__COMO__)			//comeau
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__CODEGEARC__)&&(__CODEGEARC__ >=650)
	//C++Builder (XE3 or greater)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__DMC__)			//Digital Mars
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__GNUC__)&&((__GNUC__ >3)||(defined(__GNUC_MINOR__)&&(__GNUC__ ==3)&&(__GNUC_MINOR__ >=4)))
	//GCC
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__HP_aCC)&&(__HP_aCC >=61200)
	//HP aC++ (A.06.12)
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__xlC__)&&((__xlC__ >1301)||((__xlC__ ==1301)&&(__xlC_ver__ >0100)))
	//IBM
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__INTEL_COMPILER)||defined(__ICC)||defined(__ECC)||defined(__ICL)
	//intel
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__POCC__)			//Pelles C
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__CC_ARM)			//ARM compiler
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__IAR_SYSTEMS_ICC__)	//IAR C/C++
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 1
#elif defined(__PGI)			//Portland Group C/C++
	#define AURORA_TARGET_PRAGMA_ONCE_SUPPORT 0
#endif

#endif // INCLUDE_H_AURORA_LIB_TARGET
