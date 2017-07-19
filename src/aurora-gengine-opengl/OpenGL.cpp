#include <Aurora/GEngine/OpenGL.h>
#include <iostream>

namespace Aurora {
	namespace GEngine {
		const char* getGLVersion() {
			if(glewInit() != GLEW_OK)
            {
                exit(EXIT_FAILURE);
            }
			return (const char*) glGetString(GL_VERSION);
		}
	}
}
