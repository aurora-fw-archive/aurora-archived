// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <sys/sysinfo.h>
#elif defined(__MACH__) && defined(__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#endif

#include <Aurora/Info/RAM.h>

namespace Aurora
{
    // Total virtual memory size in bytes
    unsigned int InfoRAM::getTotalVirtualMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram + mem_temp.totalswap) * mem_temp.mem_unit;
        #elif defined(_WIN32)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_vm;
        #endif
    }
        
    // Used virtual memory size in bytes
    unsigned int InfoRAM::getUsedVirtualMemory()
    {
        #ifdef __linux
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((mem_temp.totalram - mem_temp.freeram) + (mem_temp.totalswap - mem_temp.freeswap)) * mem_temp.mem_unit;
        #elif defined(_WIN32)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual - mem_temp.ullAvailVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_vm - mem_temp.t_free;
        #endif
    }
        
    // Free virtual memory size in bytes
    unsigned int InfoRAM::getFreeVirtualMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((mem_temp.totalram + mem_temp.totalswap) - ((mem_temp.totalram - mem_temp.freeram) + (mem_temp.totalswap - mem_temp.freeswap))) * mem_temp.mem_unit;
        #elif defined(_WIN32)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullAvailVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_free;
        #endif
    }
        
    // Total pysical memory size in bytes
    unsigned int InfoRAM::getTotalPhysicalMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.totalram * mem_temp.mem_unit;
        #elif defined(_WIN32)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalPhys;
        #elif defined(__MACH__) && defined(__APPLE__)
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
    unsigned int InfoRAM::getUsedPhysicalMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram - mem_temp.freeram) * mem_temp.mem_unit;
        #elif defined(_WIN32)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalPhys - mem_temp.ullAvailPhys;
        #elif defined(__MACH__) && defined(__APPLE__)
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
    unsigned int InfoRAM::getFreePhysicalMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.freeram * mem_temp.mem_unit;
        #elif defined(_WIN32)
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullAvailPhys;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmmeter mem_temp;
        vmmeter (&mem_temp);
        return mem_temp.v_free_count;
        #endif
    }
}