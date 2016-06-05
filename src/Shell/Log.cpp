#include <iostream>
#include <Aurora/ShellLog.h>

namespace AuroraShell
{
    void Log::Error (std::string body, bool newline)
    {
        std::cout << "[ERROR] " << body ;
        if(newline) std::cout << std::endl;
    }
    void Log::Warning (std::string body, bool newline)
    {
        std::cout << "[WARNING] " << body ;
        if(newline) std::cout << std::endl;
    }
    void Log::Notice (std::string body, bool newline)
    {
        std::cout << "[NOTICE] " << body ;
        if(newline) std::cout << std::endl;
    }
    void Log::Information (std::string body, bool newline)
    {
        std::cout << "[INFORMATION] " << body ;
        if(newline) std::cout << std::endl;
    }
}