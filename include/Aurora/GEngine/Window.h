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
            WindowProperties(uint , uint , bool = false, bool = false);
            uint width, height;
		    bool fullscreen;
            bool vsync;
        };

        class AURORA_PREFIX Window
        {
        	public:
        		Window(const char* name , const WindowProperties& );

        	private:
                //void Init();
        		GLFWwindow *window;
        		const unsigned long ID;
                const char* name;
                const int width, height;
        };
    }
}

#endif // INCLUDE_H_AURORA_GENGINE_WINDOW
