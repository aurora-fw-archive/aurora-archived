#include <Aurora/GEngine/Window.h>

namespace Aurora {
    namespace GEngine {
        Window::Window(Ar::String name, int width, int height)
            : width(width), height(height)
        {
            this->name = name.toCString();
            Init();
        }

        Window::Window(const char *name, int width, int height)
            : name((char*) name), width(width), height(height)
        {
            Init();
        }
    }
}
