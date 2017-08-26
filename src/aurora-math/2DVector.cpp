#include <Aurora/Math/2DVector.h>

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

		Vector2D::Vector2D(const vec3& v)
		{
			this->x = v.x;
			this->y = v.y;
		}

		Vector2D& Vector2D::Add(const Vector2D& v)
		{
			x += v.x;
			y += v.y;

			return *this;
		}

		Vector2D& Vector2D::Subtract(const Vector2D& v)
		{
			x -= v.x;
			y -= v.y;

			return *this;
		}

		Vector2D& Vector2D::Multiply(const Vector2D& v)
		{
			x *= v.x;
			y *= v.y;

			return *this;
		}

		Vector2D& Vector2D::Divide(const Vector2D& v)
		{
			x /= v.x;
			y /= v.y;

			return *this;
		}

		Vector2D& Vector2D::Add(float val)
		{
			x += val;
			y += val;

			return *this;
		}

		Vector2D& Vector2D::Subtract(float val)
		{
			x -= val;
			y -= val;

			return *this;
		}

		Vector2D& Vector2D::Multiply(float val)
		{
			x *= val;
			y *= val;

			return *this;
		}

		Vector2D& Vector2D::Divide(float val)
		{
			x /= val;
			y /= val;

			return *this;
		}

		Vector2D operator+(Vector2D left, const Vector2D& right)
		{
			return left.Add(right);
		}

		Vector2D operator-(Vector2D left, const Vector2D& right)
		{
			return left.Subtract(right);
		}

		Vector2D operator*(Vector2D left, const Vector2D& right)
		{
			return left.Multiply(right);
		}

		Vector2D operator/(Vector2D left, const Vector2D& right)
		{
			return left.Divide(right);
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
			return Add(other);
		}

		Vector2D& Vector2D::operator-=(const Vector2D& other)
		{
			return Subtract(other);
		}

		Vector2D& Vector2D::operator*=(const Vector2D& other)
		{
			return Multiply(other);
		}

		Vector2D& Vector2D::operator/=(const Vector2D& other)
		{
			return Divide(other);
		}

		Vector2D& Vector2D::operator+=(float value)
		{
			return Add(value);
		}

		Vector2D& Vector2D::operator-=(float value)
		{
			return Subtract(value);
		}

		Vector2D& Vector2D::operator*=(float value)
		{
			return Multiply(value);
		}

		Vector2D& Vector2D::operator/=(float value)
		{
			return Divide(value);
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

		float Vector2D::Distance(const Vector2D& other) const
		{
			float a = x - other.x;
			float b = y - other.y;
			return sqrt(a * a + b * b);
		}

		float Vector2D::Dot(const Vector2D& other) const
		{
			return x * other.x + y * other.y;
		}

		float Vector2D::Magnitude() const
		{
			return sqrt(x * x + y * y);
		}

		Vector2D Vector2D::Normalise() const
		{
			float length = Magnitude();
			return Vector2D(x / length, y / length);
		}

		String Vector2D::ToString() const
		{
			std::stringstream result;
			result << "Vector2D: (" << x << ", " << y << ")";
			return result.str();
		}

		std::ostream& operator<<(std::ostream& stream, const Vector2D& vector)
		{
			stream << vector.ToString();
			return stream;
		}
	}
}
