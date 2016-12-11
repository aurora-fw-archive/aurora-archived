#pragma once

#include <Aurora/Lib/String.h>

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
