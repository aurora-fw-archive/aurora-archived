#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_WINDOW
#define INCLUDE_H_AURORA_GENGINE_WINDOW

#include <Aurora/GEngine/Application.h>

#include <Aurora/GEngine/OpenGL.h>
#include <Aurora/GEngine/Vulkan.h>
#include <Aurora/GEngine/GLFW.h>

//typedef struct GLFWwindow GLFWwindow;
//typedef struct GLFWmonitor GLFWmonitor;

namespace Aurora {
    namespace GEngine {
        struct AURORA_PREFIX WindowProperties {
            WindowProperties(uint , uint , bool = false, bool = false);
            uint width, height;
		    bool fullscreen;
            bool vsync;
        };

        class AURORA_PREFIX Window
        {
        	public:
        		Window(GEngine::Application , const char* , const WindowProperties& );
                ~Window();
                void Update();
                void Clear() const;
                bool isClosed() const;
                inline uint getWidth() const { return width; }
                inline uint getHeight() const { return height; }

        	private:
                //void Init();
        		GLFWwindow *window;
                const GLFWmonitor *monitor;
        		const unsigned long ID;
                const char* name;
                uint width, height;
                const bool fullscreen, vsync;
        };
    }
}

#endif // INCLUDE_H_AURORA_GENGINE_WINDOW
