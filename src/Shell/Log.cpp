// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <Aurora/ShellLog.h>

namespace AuroraShell
{
    void Log::Error (std::string body, bool newline)
    {
        #ifdef __unix__
        std::cout << "\e[1m[\e[1;31mERROR\e[0;1m] \e[0m" << body ;
        #else
        std::cout << "[ERROR] " << body ;
        #endif
        if(newline) std::cout << std::endl;
    }
    void Log::Warning (std::string body, bool newline)
    {
        #ifdef __unix__
        std::cout << "\e[1m[\e[1;33mWARNING\e[0;1m] \e[0m" << body ;
        #else
        std::cout << "[WARNING] " << body ;
        #endif
        if(newline) std::cout << std::endl;
    }
    void Log::Notice (std::string body, bool newline)
    {
        #ifdef __unix__
        std::cout << "\e[1m[\e[1;36mNOTICE\e[0;1m] \e[0m" << body ;
        #else
        std::cout << "[NOTICE] " << body ;
        #endif
        if(newline) std::cout << std::endl;
    }
    void Log::Information (std::string body, bool newline)
    {
        #ifdef __unix__
        std::cout << "\e[1m[\e[1;32mINFORMATION\e[0;1m] \e[0m" << body ;
        #else
        std::cout << "[INFORMATION] " << body ;
        #endif
        if(newline) std::cout << std::endl;
    }
}