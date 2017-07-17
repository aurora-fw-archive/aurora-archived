#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_WINDOW
#define INCLUDE_H_AURORA_GENGINE_WINDOW

#include <Aurora/GEngine/Application.h>

namespace Aurora {
    namespace GEngine {
        typedef struct _GLFWwindow GLFWwindow;

        struct AURORA_PREFIX WindowProperties {
            uint width, height;
		    bool fullscreen;
            bool vsync;
        };

        class AURORA_PREFIX Window
        {
        	public:
        		Window(Application* , const WindowProperties& );

        	private:
                //void Init();
        		GLFWwindow *window;
        		unsigned long ID = 0;
                char* name;
                int width, height;
        };
    }
}

#endif // INCLUDE_H_AURORA_GENGINE_WINDOW
