// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: include/Aurora/Core/Target.h
// Contains: Targets for Operation System / Kernel / Platform Detection

#ifndef _AURORA_CORE_TARGETS
#define _AURORA_CORE_TARGETS

// TODO: Implement this macros ( https://sourceforge.net/p/predef/wiki/OperatingSystems/ )

#ifdef _WIN32
    #define AURORA_TARGET_WINDOW
    #define AURORA_TARGET_WINDOWS_86_64
    #ifdef _WIN64
        #define AURORA_TARGET_WINDOWS_64
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
    #ifdef __gnu_linux__
        #define AURORA_TARGET_GNU_LINUX
    #endif
#endif

#ifdef __ANDROID__
    #define AURORA_TARGET_ANDROID
#elif __CYGWIN__
    #define AURORA_TARGET_CYGWIN
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    #define AURORA_TARGET_FREEBSD
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
#elif defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
    #define AURORA_TARGET_CPU_ITANIUM
#elif defined(__sparc)
    #define AURORA_TARGET_CPU_SPARC
#elif defined(__arm__)
    #define AURORA_TARGET_CPU_ARM
#endif

// TODO: Include Compiler Targets ( https://sourceforge.net/p/predef/wiki/Compilers/ )

#if defined(__GNUG__) || (defined(__GNUC__) && defined(__cplusplus))
    #define AURORA_TARGET_COMPILER_GNU_CXX        
    #define AURORA_TARGET_CXX
    #ifdef __GNUC__
        #define AURORA_TARGET_CC
    #endif
#elif defined(__GNUC__)
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

#endif // _AURORA_CORE_TARGETS