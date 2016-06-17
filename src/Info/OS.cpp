// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Info/OS.h>

namespace Aurora
{
    std::string InfoOS::getManufacturer()
    {
        #ifdef AURORA_TARGET_WINDOW
            return "Microsoft Corporation";
        #elif defined(AURORA_TARGET_APPLE)
            return "Apple Inc.";
        #elif defined(AURORA_TARGET_LINUX) || defined(AURORA_TARGET_FREEBSD)
            return "Community (Open Source)";
        #else
            return "Unknown Manufacturer";
        #endif
    }
    std::string InfoOS::getArchitecture()
    {
        #ifdef AURORA_TARGET_CPU_I386
            return "x86 32-bit";
        #elif defined(AURORA_TARGET_CPU_86_64)
            return "x86 64-bit";
        #elif defined(AURORA_TARGET_CPU_ARM)
            return "ARM";
        #else
            return "Unknown Architecture";
        #endif
    }
    std::string InfoOS::getName()
    {
        #ifdef AURORA_TARGET_WINDOW
            // TODO: Detect Windows Name with integrated version
        #elif defined(AURORA_TARGET_LINUX)
            #ifdef AURORA_TARGET_GNU_LINUX
                // TODO: Detect Linux Distribution name
            #endif
        #endif

    }
}