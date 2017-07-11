#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#include <Aurora/TLib/String.h>

namespace Aurora {
    namespace GEngine {
        typedef struct _GLFWwindow GLFWwindow;

        class Window
        {
        	public:
        		Window(Ar::String, int, int);
                Window(const char*, int, int);

        	private:
                void Init();
        		GLFWwindow *window;
        		unsigned long ID = 0;
                char* name;
                int width, height;
        };
    }
}
