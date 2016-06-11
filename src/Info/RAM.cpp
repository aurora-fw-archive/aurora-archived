// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/sysinfo.h>
#elif __APPLE__
// #include <sys/sysctl.h>
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
        #elif _WIN32
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
        #elif _WIN32
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalVirtual - mem_temp.ullAvailVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        struct xsw_usage swmem_temp;
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
        #elif _WIN32
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullAvailVirtual;
        #elif defined(__MACH__) && defined(__APPLE__)
        struct vmtotal mem_temp;
        struct xsw_usage swmem_temp;
        vmtotal (&mem_temp);
        return mem_temp.t_free;
        #endif
    }
        
    // Total pysical memory size in bytes
    unsigned int InfoRAM::getTotalPhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.totalram * mem_temp.mem_unit;
    }
        
    // Used pysical memory size in bytes
    unsigned int InfoRAM::getUsedPhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram - mem_temp.freeram) * mem_temp.mem_unit;
    }
        
    // Free pysical memory size in bytes
    unsigned int InfoRAM::getFreePhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.freeram * mem_temp.mem_unit;
    }
}