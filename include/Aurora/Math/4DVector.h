#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_MATH_4DVECTOR
#define INCLUDE_H_AURORA_MATH_4DVECTOR

#include <Aurora/Math/3DVector.h>

namespace Aurora {
	namespace Math {
		struct vec3;

		struct AURORA_PREFIX vec4 {
			vec4();
			vec4(float );
			vec4(float , float , float , float );
			vec4(const vec3& , float );

			vec4& Add(const vec4& );
			vec4& Subtract(const vec4& );
			vec4& Multiply(const vec4& );
			vec4& Divide(const vec4& );

			friend vec4 operator+(vec4 , const vec4& );
			friend vec4 operator-(vec4 , const vec4& );
			friend vec4 operator*(vec4 , const vec4& );
			friend vec4 operator/(vec4 , const vec4& );

			bool operator==(const vec4& ) const;
			bool operator!=(const vec4& ) const;

			vec4& operator+=(const vec4& );
			vec4& operator-=(const vec4& );
			vec4& operator*=(const vec4& );
			vec4& operator/=(const vec4& );

			friend std::ostream& operator<<(std::ostream& , const vec4& );

			float x, y, z, w;
		};
	}
}

#endif // INCLUDE_H_AURORA_MATH_4DVECTOR
