#ifndef AURORA_MODULE_CORE_TLIB
	#define AURORA_MODULE_CORE_TLIB
#endif /// AURORA_MODULE_CORE_TLIB

#include <Aurora/Lib/Target/Platform.h>

#ifdef __ANDROID__
	#define AURORA_TARGET_PLATFORM_ANDROID
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
