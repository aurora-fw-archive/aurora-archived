// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Lib/Target.h>
#include <Aurora/Info/OS.h>

#ifdef AURORA_TARGET_GNU_LINUX
#include <sys/utsname.h>
#elif defined(AURORA_TARGET_WINDOWS)
#include <windows.h>
#endif

namespace Aurora
{
    std::string InfoOS::getManufacturer()
    {
        #ifdef AURORA_TARGET_WINDOWS
            return "Microsoft Corporation";
        #elif defined(AURORA_TARGET_APPLE)
            return "Apple Inc.";
        #elif defined(AURORA_TARGET_IS_OPENSOURCE)
            return "Community (Open Source)";
        #else
            return "Unknown Manufacturer";
        #endif
    }
    std::string InfoOS::getArchitecture()
    {
        #ifdef AURORA_TARGET_GNU_LINUX
            struct utsname linuxname_temp;
            uname(&linuxname_temp);
            return std::string(linuxname_temp.machine);
        #else
            #ifdef AURORA_TARGET_CPU_I386
                return "x86 32-bit";
            #elif defined(AURORA_TARGET_CPU_86_64)
                return "x86 64-bit";
            #elif defined(AURORA_TARGET_CPU_ARM)
                return "Arm";
            #else
                return "Unknown Architecture";
            #endif
        #endif
    }
    std::string InfoOS::getName()
    {
        #ifdef AURORA_TARGET_WINDOWS
            return "Microsoft Windows";
        #elif defined(AURORA_TARGET_GNU_LINUX)
            struct utsname linuxname_temp;
            uname(&linuxname_temp);
            return std::string(linuxname_temp.sysname);
        #elif defined(AURORA_TARGET_ANDROID)
            return "Android";
        #else
            return "Unknown Operation System";
        #endif
    }

    std::string InfoOS::getVersion()
    {
        // TODO: Get Version for Windows Platforms
        #ifdef AURORA_TARGET_GNU_LINUX
            struct utsname linuxname_temp;
            uname(&linuxname_temp);
            return std::string(linuxname_temp.release) + std::string(linuxname_temp.version);
        #else
            return "Unknown Version";
        #endif
    }

    std::string InfoOS::getUserComputerName()
    {
        // TODO: Get User computer name for others platforms
        #ifdef AURORA_TARGET_GNU_LINUX
            struct utsname linuxname_temp;
            uname(&linuxname_temp);
            return std::string(linuxname_temp.nodename);
		#elif defined(AURORA_TARGET_WINDOWS)
			return "Unknown";
        #endif
    }
}