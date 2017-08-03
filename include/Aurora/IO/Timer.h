#pragma once

#include <Aurora/Common.h>

#include <Aurora/TLib/Target/Environment.h>
#include <Aurora/TLib/Target/Platform.h>

#ifdef AURORA_TARGET_ENVIRONMENT_POSIX
#include <chrono>
#elif defined(AURORA_TARGET_PLATFORM_WINDOWS)
#include <Windows.h>
#endif

namespace Aurora {
	namespace IO {
		#ifdef AURORA_TARGET_ENVIRONMENT_POSIX
		typedef std::chrono::high_resolution_clock HighResolutionClock;
		typedef std::chrono::duration<float, std::milli> milliseconds_type;
		#endif

		class AURORA_PREFIX Timer
		{
		private:
			#ifdef AURORA_TARGET_ENVIRONMENT_POSIX
			std::chrono::time_point<HighResolutionClock> start;
			#elif AURORA_TARGET_PLATFORM_WINDOWS
			LARGE_INTEGER start;
			double frequency;
			#endif

		public:
			Timer();
			void Reset();
			float Elapsed();
			float ElapsedMillis();
		};
	}
}
