#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_MATH_3DVECTOR
#define INCLUDE_H_AURORA_MATH_3DVECTOR

#include <ostream>
#include <Aurora/Math/2DVector.h>
#include <Aurora/Math/4DVector.h>

namespace Aurora {
	namespace Math {
		struct vec2;
		struct vec4;

		struct AURORA_PREFIX vec3 {
			vec3();
			vec3(float );
			vec3(float , float , float );
			vec3(const vec2& );
			vec3(float , float );
			vec3(const vec4& );

			vec3& Add(const vec3& );
			vec3& Subtract(const vec3& );
			vec3& Multiply(const vec3& );
			vec3& Divide(const vec3& );

			vec3& Add(float );
			vec3& Subtract(float );
			vec3& Multiply(float );
			vec3& Divide(float );

			friend vec3 operator+(vec3 , const vec3& );
			friend vec3 operator-(vec3 , const vec3& );
			friend vec3 operator*(vec3 , const vec3& );
			friend vec3 operator/(vec3 , const vec3& );

			friend vec3 operator+(vec3 , float );
			friend vec3 operator-(vec3 , float );
			friend vec3 operator*(vec3 , float );
			friend vec3 operator/(vec3 , float );

			bool operator==(const vec3& ) const;
			bool operator!=(const vec3& ) const;

			vec3& operator+=(const vec3& );
			vec3& operator-=(const vec3& );
			vec3& operator*=(const vec3& );
			vec3& operator/=(const vec3& );

			vec3& operator+=(float );
			vec3& operator-=(float );
			vec3& operator*=(float );
			vec3& operator/=(float );

			bool operator<(const vec3& ) const;
			bool operator<=(const vec3& ) const;
			bool operator>(const vec3& ) const;
			bool operator>=(const vec3& ) const;

			friend std::ostream& operator<<(std::ostream& , const vec3& );

			float x, y, z;
		};
	}
}

#endif // INCLUDE_H_AURORA_MATH_3DVECTOR
