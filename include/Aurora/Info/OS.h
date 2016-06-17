// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_INFO_OS
#define _AURORA_INFO_OS

#include <iostream>
#include <Aurora/Core/Targets.h>

#ifdef AURORA_TARGET_ANDROID
    #include <android/api-level.h>
#endif

namespace Aurora
{
    struct InfoOS 
    {
    public:
        static std::string getManufacturer();
        static std::string getArchitecture();
        static std::string getVersion();
        static std::string getName();
        static std::string getUserComputerName();
    };
}

#endif // _AURORA_INFO_OS