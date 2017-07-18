#include <Aurora/GEngine/Window.h>
#include <Aurora/Core/Debug.h>
//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Aurora {
    namespace GEngine {
        WindowProperties::WindowProperties(uint width, uint height, bool fullscreen, bool vsync)
            : width(width), height(height), fullscreen(fullscreen), vsync(vsync)
        {}

        Window::Window(void (*mainFunction)(), const char* name, const WindowProperties& wp)
            : name(name), width(wp.width), height(wp.height), fullscreen(wp.fullscreen), vsync(wp.vsync),
              ID(( unsigned long ) Aurora::Debug::LastID)
        {
            Aurora::Debug::LastID++;
            if (!glfwInit())
                exit(EXIT_FAILURE);

            /* Create a windowed mode window and its OpenGL context */
            window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), NULL);
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }

            /* Make the window's context current */
            glfwMakeContextCurrent(window);

            /* Loop until the user closes the window */
            while (!glfwWindowShouldClose(window))
            {
                (*mainFunction)();

                /* Render here */
                glClear(GL_COLOR_BUFFER_BIT);

                /* Swap front and back buffers */
                glfwSwapBuffers(window);

                /* Poll for and process events */
                glfwPollEvents();
            }
        }
        Window::~Window() {

        }
    }
}
