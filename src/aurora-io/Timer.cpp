#include <Aurora/IO/Timer.h>

namespace Aurora {
	namespace IO {
		Timer::Timer() {
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
			LARGE_INTEGER freq;
			QueryPerformanceFrequency(&freq);
			frequency = 1.0 / freq.QuadPart;
			#endif

			Reset();
		}

		void Timer::Reset() {
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
			QueryPerformanceCounter(&start);
			#elif defined(AURORA_TARGET_ENVIRONMENT_POSIX)
			start = HighResolutionClock::now();
			#endif
		}

		float Timer::Elapsed() {
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			uint64 cycles = current.QuadPart - start.QuadPart;
			return (float)(cycles * frequency);
			#elif defined(AURORA_TARGET_ENVIRONMENT_POSIX)
			return ElapsedMillis() / 1000.0f;
			#endif
		}

		float Timer::ElapsedMillis() {
			#ifdef AURORA_TARGET_PLATFORM_WINDOWS
			return Elapsed() * 1000.0f;
			#elif defined(AURORA_TARGET_ENVIRONMENT_POSIX)
			return std::chrono::duration_cast<milliseconds_type>(HighResolutionClock::now() - start).count();
			#endif
		}
	}
}
