// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/TLib/Target/Platform.h>

#ifdef AURORA_TARGET_PLATFORM_WINDOWS
#include <windows.h>
#elif defined(AURORA_TARGET_PLATFORM_GNU_LINUX)
#include <sys/sysinfo.h>
#elif defined(AURORA_TARGET_PLATFORM_APPLE_MAC)
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#endif

#include <Aurora/Info/RAM.h>

namespace Aurora
{
    // Total virtual memory size in bytes
    unsigned long InfoRAM::getTotalVirtualMemory()
    {
        #ifdef AURORA_TARGET_PLATFORM_GNU_LINUX
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram + mem_temp.totalswap) * mem_temp.mem_unit;
        #elif defined(AURORA_TARGET_PLATFORM_WINDOWS)

        // TODO: Needs to be tested
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual;
        #elif defined(AURORA_TARGET_PLATFORM_APPLE_MAC)

        // TODO: Needs to be tested
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_vm;
        #endif
    }

    // Used virtual memory size in bytes
    unsigned long InfoRAM::getUsedVirtualMemory()
    {
        #ifdef AURORA_TARGET_PLATFORM_GNU_LINUX
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((mem_temp.totalram - mem_temp.freeram) + (mem_temp.totalswap - mem_temp.freeswap)) * mem_temp.mem_unit;
        #elif defined(AURORA_TARGET_PLATFORM_WINDOWS)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual - mem_temp.ullAvailVirtual;
        #elif defined(AURORA_TARGET_PLATFORM_APPLE_MAC)
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_vm - mem_temp.t_free;
        #endif
    }

    // Free virtual memory size in bytes
    unsigned long InfoRAM::getFreeVirtualMemory()
    {
        #ifdef AURORA_TARGET_PLATFORM_GNU_LINUX
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((mem_temp.totalram + mem_temp.totalswap) - ((mem_temp.totalram - mem_temp.freeram) + (mem_temp.totalswap - mem_temp.freeswap))) * mem_temp.mem_unit;
        #elif defined(AURORA_TARGET_WINDOWS)

        // TODO: Needs to be tested
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullAvailVirtual;
        #elif defined(AURORA_TARGET_PLARFORM_APPLE_MAC)

        // TODO: Needs to be tested
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_free;
        #endif
    }

    // Total pysical memory size in bytes
    unsigned long InfoRAM::getTotalPhysicalMemory()
    {
        #ifdef AURORA_TARGET_PLATFORM_GNU_LINUX
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.totalram * mem_temp.mem_unit;
        #elif defined(AURORA_TARGET_PLATFORM_WINDOWS)

        // TODO: Needs to be tested
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalPhys;
        #elif defined(AURORA_TARGET_PLATFORM_APPLE_MAC)

        // TODO: Needs to be tested
        int mib[2];
        int64_t physical_memory;
        size_t length;
        // Get the Physical memory size
        mib[0] = CTL_HW;
        mib[1] = HW_MEMSIZE;
        length = sizeof(int64);
        sysctl(mib, 2, &physical_memory, &length, NULL, 0);
        return physical_memory;
        #endif

    }

    // Used pysical memory size in bytes
    unsigned long InfoRAM::getUsedPhysicalMemory()
    {
        #ifdef AURORA_TARGET_PLATFORM_GNU_LINUX
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram - mem_temp.freeram) * mem_temp.mem_unit;
        #elif defined(AURORA_TARGET_PLATFORM_WINDOWS)

        // TODO: Needs to be tested
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalPhys - mem_temp.ullAvailPhys;
        #elif defined(AURORA_TARGET_PLATFORM_APPLE_MAC)

        // TODO: Needs to be tested
        struct vmmeter mem_temp;
        vmmeter (&mem_temp);
        int mib[2];
        int64_t physical_memory;
        size_t length;
        // Get the Physical memory size
        mib[0] = CTL_HW;
        mib[1] = HW_MEMSIZE;
        length = sizeof(int64);
        sysctl(mib, 2, &physical_memory, &length, NULL, 0);
        return physical_memory - mem_temp.v_free_count;
        #endif
    }

    // Free pysical memory size in bytes
    unsigned long InfoRAM::getFreePhysicalMemory()
    {
        #ifdef AURORA_TARGET_PLATFORM_GNU_LINUX
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.freeram * mem_temp.mem_unit;
        #elif defined(AURORA_TARGET_PLATFORM_WINDOWS)

        // TODO: Needs to be tested
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullAvailPhys;
        #elif defined(AURORA_TARGET_PLATFORM_APPLE_MAC)

        // TODO: Needs to be tested
        struct vmmeter mem_temp;
        vmmeter (&mem_temp);
        return mem_temp.v_free_count;
        #endif
    }
}
