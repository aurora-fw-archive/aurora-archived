#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/TLib/Target/Platform.h>

#if defined(__linux__) || defined(__linux) || defined(linux)
    #define AURORA_TARGET_KERNEL_LINUX
#elif defined(AURORA_TARGET_PLATFORM_WINDOWS)
    #define AURORA_TARGET_KERNEL_NT
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    #define AURORA_TARGET_KERNEL_FREEBSD
#elif defined(__OpenBSD__)
    #define AURORA_TARGET_KERNEL_OPENBSD
#elif defined(__NetBSD__)
    #define AURORA_TARGET_KERNEL_NETBSD
#elif defined(__DragonFly__)
    #define AURORA_TARGET_KERNEL_DRAGONFLY
#endif
