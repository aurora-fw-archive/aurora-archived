#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/TLib/Target/Platform.h>

#if defined(__unix__) || defined(__unix) || defined(unix)
	#define AURORA_TARGET_ENVIRONMENT_UNIX
#elif defined(__CYGWIN__)
    #define AURORA_TARGET_CYGWIN
#endif

#if defined(AURORA_TARGET_ENVIRONMENT_UNIX) || defined(AURORA_TARGET_PLATFORM_APPLE_MAC)
    #define AURORA_TARGET_ENVIRONMENT_POSIX
#endif
