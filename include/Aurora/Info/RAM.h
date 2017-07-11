// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_INFO_RAM
#define INCLUDE_H_AURORA_INFO_RAM

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

namespace Aurora
{
    class InfoRAM
    {
    public:
        static unsigned long getTotalVirtualMemory(); // Total virtual memory size in bytes
        static unsigned long getUsedVirtualMemory(); // Used virtual memory size in bytes
        static unsigned long getFreeVirtualMemory(); // Free virtual memory size in bytes
        static unsigned long getTotalPhysicalMemory(); // Total pysical memory size in bytes
        static unsigned long getUsedPhysicalMemory(); // Used pysical memory size in bytes
        static unsigned long getFreePhysicalMemory(); // Free pysical memory size in bytes
    };
}

#endif // INCLUDE_H_AURORA_INFO_RAM
