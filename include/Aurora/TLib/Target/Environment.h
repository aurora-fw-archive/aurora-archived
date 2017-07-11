#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#if defined(__unix__) || defined(__unix) || defined(unix)
	#define AURORA_TARGET_ENVIRONMENT_UNIX
#elif defined(__CYGWIN__)
    #define AURORA_TARGET_CYGWIN
#endif
