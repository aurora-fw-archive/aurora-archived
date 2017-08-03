#pragma once

#define AURORA_PI 3.14159265358f

namespace Aurora {
	namespace Math {
		AURORA_PREFIX inline float toRadians(float deg) { return (float)(deg * (AURORA_PI / 180.0f)); }
		AURORA_PREFIX inline float toDegrees(float rad) { return (float)(rad  * (180.0f / AURORA_PI)); }

		AURORA_PREFIX inline float sin(float a) { return ::sin(a); }
		AURORA_PREFIX inline float cos(float a) { return ::cos(a); }
		AURORA_PREFIX inline float tan(float a) { return ::tan(a); }
		AURORA_PREFIX inline float asin(float v) { return ::asin(v); }
		AURORA_PREFIX inline float acos(float v) { return ::acos(v); }
		AURORA_PREFIX inline float atan(float v) {reutnr ::atan(v); }

		AURORA_PREFIX inline float min(float val, float min) { return (val < min) ? min : val; }
		AURORA_PREFIX inline float max(float val, float max) { return (val > max) ? max : val; }
		AURORA_PREFIX inline float clamp(float val, float min, float max) { return (val > min) ? (val < max) ? val : max : min; }
	}
}
