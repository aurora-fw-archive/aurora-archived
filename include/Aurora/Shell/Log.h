// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_SHELL_LOG
#define _AURORA_SHELL_LOG

#include <iostream>
#include <Aurora/Core/Macros.h>
#include <Aurora/Shell/Output.h>

namespace Aurora { namespace Shell
    {
        const char EndLine = '\n';

        enum MessageStatus
        {
            Error,
            Warning,
            Notice,
            Information,
            Debug
        };
        void Log (MessageStatus status, auto... args);
        void Log (MessageStatus status, auto... args)
        {
            if(status == Error)
            {
                #if defined(__unix__) || defined(__unix) || \
                    (defined(__APPLE__) && defined(__MACH__))
                std::cout << "\e[0m\e[1m[\e[1;31mERROR\e[0;1m] \e[0m";
                #else
                std::cout << "[ERROR] ";
                #endif
                Output(args...);
            }
            else if (status == Warning)
            {
                #if defined(__unix__) || defined(__unix) || \
                    (defined(__APPLE__) && defined(__MACH__))
                std::cout << "\e[0m\e[1m[\e[1;33mWARNING\e[0;1m] \e[0m";
                #else
                std::cout << "[WARNING] ";
                #endif
                Output(args...);
            }
            else if (status == Notice)
            {
                #if defined(__unix__) || defined(__unix) || \
                    (defined(__APPLE__) && defined(__MACH__))
                std::cout << "\e[0m\e[1m[\e[1;36mNOTICE\e[0;1m] \e[0m";
                #else
                std::cout << "[NOTICE] ";
                #endif
                Output(args...);
            }
            else if (status == Information)
            {
                #if defined(__unix__) || defined(__unix) || \
                (defined(__APPLE__) && defined(__MACH__))
                std::cout << "\e[0m\e[1m[\e[1;32mINFORMATION\e[0;1m] \e[0m";
                #else
                std::cout << "[INFORMATION] ";
                #endif
                Output(args...);
            }
            else if (status == Aurora::Shell::Debug)
            {
                if(Aurora::Debug)
                {
                    #if defined(__unix__) || defined(__unix) || \
                    (defined(__APPLE__) && defined(__MACH__))
                    std::cout << "\e[0m\e[1m[\e[1;36mDEBUG\e[0;1m] \e[0m";
                    #else
                    std::cout << "[DEBUG] ";
                    #endif
                    Output(args...);
                }
            }
        }
    }
}

#endif // _AURORA_SHELL_LOG