#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_MATH_4DVECTOR
#define INCLUDE_H_AURORA_MATH_4DVECTOR

#include <Aurora/Math/Vector3D.h>

namespace Aurora {
	namespace Math {
		struct vec3;

		struct AURORA_PREFIX Vector4D {
			Vector4D();
			Vector4D(float );
			Vector4D(float , float , float , float );
			Vector4D(const vec3& , float );

			Vector4D& Add(const Vector4D& );
			Vector4D& Subtract(const Vector4D& );
			Vector4D& Multiply(const Vector4D& );
			Vector4D& Divide(const Vector4D& );

			friend Vector4D operator+(Vector4D , const Vector4D& );
			friend Vector4D operator-(Vector4D , const Vector4D& );
			friend Vector4D operator*(Vector4D , const Vector4D& );
			friend Vector4D operator/(Vector4D , const Vector4D& );

			bool operator==(const Vector4D& ) const;
			bool operator!=(const Vector4D& ) const;

			Vector4D& operator+=(const Vector4D& );
			Vector4D& operator-=(const Vector4D& );
			Vector4D& operator*=(const Vector4D& );
			Vector4D& operator/=(const Vector4D& );

			friend std::ostream& operator<<(std::ostream& , const Vector4D& );

			float x, y, z, w;
		};
	}
}

#endif // INCLUDE_H_AURORA_MATH_4DVECTOR
