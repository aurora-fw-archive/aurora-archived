#include <Aurora/GEngine/Window.h>
#include <Aurora/Core/Debug.h>

namespace Aurora {
    namespace GEngine {
        WindowProperties::WindowProperties(uint width, uint height, bool fullscreen, bool vsync)
            : width(width), height(height), fullscreen(fullscreen), vsync(vsync)
        {}

        Window::Window(const char*, const WindowProperties& wp)
            : width(wp.width), height(wp.height),
              ID(( unsigned long ) Aurora::Debug::LastID)
        {
            Aurora::Debug::LastID++;
        }
    }
}
