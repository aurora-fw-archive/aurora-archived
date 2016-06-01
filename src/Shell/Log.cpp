#include <iostream>
#include <Aurora/ShellLog.h>

namespace ShellLog
{
    void Error (std::string body, bool newline)
    {
        std::cout << "[ERROR] " << body ;
        if(newline) std::endl;
    }
    void Warning (std::string body, bool newline)
    {
        std::cout << "[WARNING] " << body ;
        if(newline) std::endl;
    }
    void Notice (std::string body, bool newline)
    {
        std::cout << "[NOTICE] " << body ;
        if(newline) std::endl;
    }
    void Information (std::string body, bool newline)
    {
        std::cout << "[INFORMATION] " << body ;
        if(newline) std::endl;
    }
}