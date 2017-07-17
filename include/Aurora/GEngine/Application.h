#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_APPLICATION
#define INCLUDE_H_AURORA_GENGINE_APPLICATION

#include <Aurora/GEngine/API.h>
#include <Aurora/Core/Application.h>
#include <iostream>

namespace Aurora {
	namespace GEngine {
		class AURORA_PREFIX Application {
		public:
			Application(void (*)() , std::string , GraphicsAPI = GraphicsAPI::OpenGL , int = 0, char** = NULL);
            ~Application();
            std::string name;
        private:
            GraphicsAPI gapi;
            Aurora::Application *App;
		};
	}
}

#endif // INCLUDE_H_AURORA_GENGINE_APPLICATION
