#include <iostream>
#include <assert.h>
#include <Aurora/GEngine/Application.h>

#include <Aurora/GEngine/Direct3D.h>

namespace Aurora {
	namespace GEngine {
		Application::Application(GraphicsAPI gapi)
			: gapi(gapi)
		{
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
				LPDIRECT3D9 d3d = Direct3DCreate9( D3D_SDK_VERSION );
				D3DCAPS9 caps;
			#endif
			switch (gapi) {
				case GraphicsAPI::Vulkan:
					#ifndef AURORA_VULKAN_FOUND
					static_assert(false, "Vulkan API is not supported on this device!");
					#endif
					break;
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
				case GraphicsAPI::DirectX:
					static_assert(FAILED(d3d->GetDeviceCaps(D3DADAPTER_DEFAULT , D3DDEVTYPE_HAL, &caps)), "Direct3D API is not supported on this device!");
					break;
			#endif
				case GraphicsAPI::OpenGL: break;
			}
		}
		Application::~Application() {
		}
	}
}
