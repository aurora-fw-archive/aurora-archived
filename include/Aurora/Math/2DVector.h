#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_MATH_2DVECTOR
#define INCLUDE_H_AURORA_MATH_2DVECTOR

#include <ostream>
#include <Aurora/Math/3DVector.h>

namespace Aurora {
	namespace Math {
		struct vec3;

		struct AURORA_PREFIX vec2 {
			vec2();
			vec2(float );
			vec2(float , float );
			vec2(const vec3& );

			vec2& Add(const vec2& );
			vec2& Subtract(const vec2& );
			vec2& Multiply(const vec2& );
			vec2& Divide(const vec2& );

			vec2& Add(float );
			vec2& Subtract(float );
			vec2& Multiply(float );
			vec2& Divide(float );

			friend vec2 operator+(vec2 , const vec2& );
			friend vec2 operator-(vec2 , const vec2& );
			friend vec2 operator*(vec2 , const vec2& );
			friend vec2 operator/(vec2 , const vec2& );

			friend vec2 operator+(vec2 , float );
			friend vec2 operator-(vec2 , float );
			friend vec2 operator*(vec2 , float );
			friend vec2 operator/(vec2 , float );

			bool operator==(const vec2& ) const;
			bool operator!=(const vec2& ) const;

			vec2& operator+=(const vec2& );
			vec2& operator-=(const vec2& );
			vec2& operator*=(const vec2& );
			vec2& operator/=(const vec2& );

			vec2& operator+=(float );
			vec2& operator-=(float );
			vec2& operator*=(float );
			vec2& operator/=(float );

			bool operator<(const vec2& ) const;
			bool operator<=(const vec2& ) const;
			bool operator>(const vec2& ) const;
			bool operator>=(const vec2& ) const;

			friend std::ostream& operator<<(std::ostream& , const vec2& );

			float x, y;
		};
	}
}

#endif // INCLUDE_H_AURORA_MATH_2DVECTOR
