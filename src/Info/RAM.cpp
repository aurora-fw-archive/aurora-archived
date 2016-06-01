#include <Aurora/InfoRAM.h>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/sysinfo.h>
#elif __APPLE__
#include <sys/sysctl.h>
#endif

namespace InfoRAM
{
    // Total virtual memory size in bytes
    unsigned int getTotalVirtualMemory()
    {
        #ifdef __linux__
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (memInfo.totalram + memInfo.totalswap) * mem_temp.mem_unit;
        #elif _WIN32
        MEMORYSTATUSEX mem_temp;
        mem_temp.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_temp);
        return mem_temp.ullTotalPageFile;
        #elif __APPLE__
        #endif
    }
    
    // Used virtual memory size in bytes
    unsigned int getUsedVirtualMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((memInfo.totalram - memInfo.freeram) + (memInfo.totalswap - memInfo.freeswap)) * mem_temp.mem_unit;
    }
    
    // Free virtual memory size in bytes
    unsigned int getFreeVirtualMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return ((memInfo.totalram + memInfo.totalswap) - ((memInfo.totalram - memInfo.freeram) + (memInfo.totalswap - memInfo.freeswap))) * mem_temp.mem_unit;
    }
    
    // Total pysical memory size in bytes
    unsigned int getTotalPhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.totalram * mem_temp.mem_unit;
    }
    
    // Used pysical memory size in bytes
    unsigned int getUsedPhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return (mem_temp.totalram - mem_temp.freeram) * mem_temp.mem_unit;
    }
    
    // Free pysical memory size in bytes
    unsigned int getFreePhysicalMemory()
    {
        struct sysinfo mem_temp;
        sysinfo (&mem_temp);
        return mem_temp.freeram * mem_temp.mem_unit;
    }
}