#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

namespace Aurora {
	namespace GEngine {
		enum class GraphicsAPI
		{
			None
			OpenGL,
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
				DirectX,
			#endif
			Vulkan
		};
	}
}


Aurora::GEngine::gAPI
