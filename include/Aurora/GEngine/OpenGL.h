#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GENGINE_OPENGL
#define INCLUDE_H_AURORA_GENGINE_OPENGL

#include <GL/glew.h>
#include <GL/gl.h>
//#include <glm/glm.hpp>

namespace Aurora {
	namespace GEngine {
		const char* getGLVersion();
	}
}

#endif // INCLUDE_H_AURORA_GENGINE_OPENGL
