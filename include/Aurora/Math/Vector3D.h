#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_MATH_3DVECTOR
#define INCLUDE_H_AURORA_MATH_3DVECTOR

#include <ostream>
#include <Aurora/Math/Vector2D.h>
#include <Aurora/Math/Vector4D.h>

namespace Aurora {
	namespace Math {
		struct vec2;
		struct vec4;

		struct AURORA_PREFIX Vector3D {
			Vector3D();
			Vector3D(float );
			Vector3D(float , float , float );
			Vector3D(const vec2& );
			Vector3D(float , float );
			Vector3D(const vec4& );

			Vector3D& Add(const Vector3D& );
			Vector3D& Subtract(const Vector3D& );
			Vector3D& Multiply(const Vector3D& );
			Vector3D& Divide(const Vector3D& );

			Vector3D& Add(float );
			Vector3D& Subtract(float );
			Vector3D& Multiply(float );
			Vector3D& Divide(float );

			friend Vector3D operator+(Vector3D , const Vector3D& );
			friend Vector3D operator-(Vector3D , const Vector3D& );
			friend Vector3D operator*(Vector3D , const Vector3D& );
			friend Vector3D operator/(Vector3D , const Vector3D& );

			friend Vector3D operator+(Vector3D , float );
			friend Vector3D operator-(Vector3D , float );
			friend Vector3D operator*(Vector3D , float );
			friend Vector3D operator/(Vector3D , float );

			bool operator==(const Vector3D& ) const;
			bool operator!=(const Vector3D& ) const;

			Vector3D& operator+=(const Vector3D& );
			Vector3D& operator-=(const Vector3D& );
			Vector3D& operator*=(const Vector3D& );
			Vector3D& operator/=(const Vector3D& );

			Vector3D& operator+=(float );
			Vector3D& operator-=(float );
			Vector3D& operator*=(float );
			Vector3D& operator/=(float );

			bool operator<(const Vector3D& ) const;
			bool operator<=(const Vector3D& ) const;
			bool operator>(const Vector3D& ) const;
			bool operator>=(const Vector3D& ) const;

			friend std::ostream& operator<<(std::ostream& , const Vector3D& );

			float x, y, z;
		};
	}
}

#endif // INCLUDE_H_AURORA_MATH_3DVECTOR
