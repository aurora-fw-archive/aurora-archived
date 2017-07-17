#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_DIRECT3D
#define INCLUDE_H_AURORA_GENGINE_DIRECT3D

#include <Aurora/TLib/Target/Platform.h>

#ifdef AURORA_TARGET_PLATFORM_WINDOWS
	#include <d3d11.h>
	#include <d3dcompiler.h>
#endif

#endif // INCLUDE_H_AURORA_GENGINE_DIRECT3D
