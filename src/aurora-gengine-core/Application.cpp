#include <Aurora/GEngine/Application.h>

#include <Aurora/GEngine.h>
#include <Aurora/GEngine/Vulkan.h>
#include <Aurora/GEngine/Direct3D.h>

#include <iostream>
#include <assert.h>

namespace Aurora {
	namespace GEngine {
		Application::Application(const char* name, GraphicsAPI gapi)
			: name(name), gapi(gapi)
		{
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
				LPDIRECT3D9 d3d = Direct3DCreate9( D3D_SDK_VERSION );
				D3DCAPS9 caps;
			#endif
			switch (gapi) {
				case GraphicsAPI::Vulkan:
					vkappinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
					vkappinfo.pNext = NULL;
					vkappinfo.pApplicationName = name;
					vkappinfo.pEngineName = "Aurora GEngine";
					vkappinfo.engineVersion = AURORA_GENGINE_VERSION;
					vkappinfo.apiVersion = VK_API_VERSION_1_0;
					break;
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
				case GraphicsAPI::DirectX: break;
			#endif
				case GraphicsAPI::OpenGL: break;
			}
		}
		Application::~Application() {
		}
	}
}
