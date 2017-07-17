#include <Aurora/GEngine/Window.h>

namespace Aurora {
    namespace GEngine {
        Window::Window(Application* parent, const WindowProperties& wp)
            : width(width), height(height)
        {
            this->name = (char*) parent->name.c_str();
        }
    }
}
