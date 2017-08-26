#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_MATH_2DVECTOR
#define INCLUDE_H_AURORA_MATH_2DVECTOR

#include <iostream>
#include <Aurora/Math/Vector3D.h>
#include <Aurora/Math/Vector4D.h>

namespace Aurora {
	namespace Math {
		struct Vector3D;
        struct Vector4D;

		struct AURORA_PREFIX Vector2D {
			Vector2D();
			Vector2D(float );
			Vector2D(float , float );
			Vector2D(const Vector3D& );
            Vector2D(const Vector4D& );

            bool isNull() const;
            float length() const;

			Vector2D& add(const Vector2D& );
			Vector2D& subtract(const Vector2D& );
			Vector2D& multiply(const Vector2D& );
			Vector2D& divide(const Vector2D& );

			Vector2D& add(float );
			Vector2D& subtract(float );
			Vector2D& multiply(float );
			Vector2D& divide(float );

            void setX(float );
            void setY(float );

			friend Vector2D operator+(Vector2D , const Vector2D& );
			friend Vector2D operator-(Vector2D , const Vector2D& );
			friend Vector2D operator*(Vector2D , const Vector2D& );
			friend Vector2D operator/(Vector2D , const Vector2D& );

			friend Vector2D operator+(Vector2D , float );
			friend Vector2D operator-(Vector2D , float );
			friend Vector2D operator*(Vector2D , float );
			friend Vector2D operator/(Vector2D , float );

			bool operator==(const Vector2D& ) const;
			bool operator!=(const Vector2D& ) const;

			Vector2D& operator+=(const Vector2D& );
			Vector2D& operator-=(const Vector2D& );
			Vector2D& operator*=(const Vector2D& );
			Vector2D& operator/=(const Vector2D& );

			Vector2D& operator+=(float );
			Vector2D& operator-=(float );
			Vector2D& operator*=(float );
			Vector2D& operator/=(float );

			bool operator<(const Vector2D& ) const;
			bool operator<=(const Vector2D& ) const;
			bool operator>(const Vector2D& ) const;
			bool operator>=(const Vector2D& ) const;

            float magnitude() const;
            Vector2D normalise() const;
            float dot(const Vector2D& ) const;
            float distance(const Vector2D& ) const;
            float distance(const Vector2D& , const Vector2D& ) const;

            std::string toString() const;

			friend std::ostream& operator<<(std::ostream& , const Vector2D& );

			float x, y;
		};
	}
}

#endif // INCLUDE_H_AURORA_MATH_2DVECTOR
