#include <Aurora/Math/Vector2D.h>
#include <string>
#include <cmath>

namespace Aurora {
	namespace Math {
		Vector2D::Vector2D()
			: x(0.0f), y(0.0f)
		{}

		Vector2D::Vector2D(float scalar)
			: x(scalar), y(scalar)
		{}

		Vector2D::Vector2D(float x, float y)
			: x(x), y(y)
		{}

		Vector2D::Vector2D(const Vector3D& v)
		{
			this->x = v.x;
			this->y = v.y;
		}

		Vector2D& Vector2D::add(const Vector2D& v)
		{
			x += v.x;
			y += v.y;

			return *this;
		}

		Vector2D& Vector2D::subtract(const Vector2D& v)
		{
			x -= v.x;
			y -= v.y;

			return *this;
		}

		Vector2D& Vector2D::multiply(const Vector2D& v)
		{
			x *= v.x;
			y *= v.y;

			return *this;
		}

		Vector2D& Vector2D::divide(const Vector2D& v)
		{
			x /= v.x;
			y /= v.y;

			return *this;
		}

		Vector2D& Vector2D::add(float val)
		{
			x += val;
			y += val;

			return *this;
		}

		Vector2D& Vector2D::subtract(float val)
		{
			x -= val;
			y -= val;

			return *this;
		}

		Vector2D& Vector2D::multiply(float val)
		{
			x *= val;
			y *= val;

			return *this;
		}

		Vector2D& Vector2D::divide(float val)
		{
			x /= val;
			y /= val;

			return *this;
		}

		Vector2D operator+(Vector2D left, const Vector2D& right)
		{
			return left.add(right);
		}

		Vector2D operator-(Vector2D left, const Vector2D& right)
		{
			return left.subtract(right);
		}

		Vector2D operator*(Vector2D left, const Vector2D& right)
		{
			return left.multiply(right);
		}

		Vector2D operator/(Vector2D left, const Vector2D& right)
		{
			return left.divide(right);
		}

		Vector2D operator+(Vector2D left, float value)
		{
			return Vector2D(left.x + value, left.y + value);
		}

		Vector2D operator-(Vector2D left, float value)
		{
			return Vector2D(left.x - value, left.y - value);
		}

		Vector2D operator*(Vector2D left, float value)
		{
			return Vector2D(left.x * value, left.y * value);
		}

		Vector2D operator/(Vector2D left, float value)
		{
			return Vector2D(left.x / value, left.y / value);
		}

		Vector2D& Vector2D::operator+=(const Vector2D& other)
		{
			return add(other);
		}

		Vector2D& Vector2D::operator-=(const Vector2D& other)
		{
			return subtract(other);
		}

		Vector2D& Vector2D::operator*=(const Vector2D& other)
		{
			return multiply(other);
		}

		Vector2D& Vector2D::operator/=(const Vector2D& other)
		{
			return divide(other);
		}

		Vector2D& Vector2D::operator+=(float value)
		{
			return add(value);
		}

		Vector2D& Vector2D::operator-=(float value)
		{
			return subtract(value);
		}

		Vector2D& Vector2D::operator*=(float value)
		{
			return multiply(value);
		}

		Vector2D& Vector2D::operator/=(float value)
		{
			return divide(value);
		}

		bool Vector2D::operator==(const Vector2D& other) const
		{
			return x == other.x && y == other.y;
		}

		bool Vector2D::operator!=(const Vector2D& other) const
		{
			return !(*this == other);
		}

		bool Vector2D::operator<(const Vector2D& other) const
		{
			return x < other.x && y < other.y;
		}

		bool Vector2D::operator<=(const Vector2D& other) const
		{
			return x <= other.x && y <= other.y;
		}

		bool Vector2D::operator>(const Vector2D& other) const
		{
			return x > other.x && y > other.y;
		}

		bool Vector2D::operator>=(const Vector2D& other) const
		{
			return x >= other.x && y >= other.y;
		}

		float Vector2D::distance(const Vector2D& other) const
		{
			float a = x - other.x;
			float b = y - other.y;
			return sqrt(a * a + b * b);
		}

		float Vector2D::dot(const Vector2D& other) const
		{
			return x * other.x + y * other.y;
		}

		float Vector2D::magnitude() const
		{
			return sqrt(x * x + y * y);
		}

		Vector2D Vector2D::normalise() const
		{
			float length = magnitude();
			return Vector2D(x / length, y / length);
		}

		std::string Vector2D::toString() const
		{
			return "Vector2D: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
		}

		std::ostream& operator<<(std::ostream& stream, const Vector2D& vector)
		{
			stream << vector.toString();
			return stream;
		}
	}
}
