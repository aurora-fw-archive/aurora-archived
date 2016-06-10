// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_INFORAM
#define _AURORA_INFORAM

namespace AuroraInfo
{
    struct RAM
    {
    public:
        static unsigned int getTotalVirtualMemory(); // Total virtual memory size in bytes
        static unsigned int getUsedVirtualMemory(); // Used virtual memory size in bytes
        static unsigned int getFreeVirtualMemory(); // Free virtual memory size in bytes
        static unsigned int getTotalPhysicalMemory(); // Total pysical memory size in bytes
        static unsigned int getUsedPhysicalMemory(); // Used pysical memory size in bytes
        static unsigned int getFreePhysicalMemory(); // Free pysical memory size in bytes
    };
}

#endif // _AURORA_INFORAM