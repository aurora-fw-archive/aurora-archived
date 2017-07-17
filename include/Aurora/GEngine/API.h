#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_API
#define INCLUDE_H_AURORA_GENGINE_API

namespace Aurora {
	namespace GEngine {
		enum class GraphicsAPI
		{
			OpenGL,
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
				Direct3D,
			#endif
			Vulkan
		};
	}
}

#endif // INCLUDE_H_AURORA_GENGINE_API
