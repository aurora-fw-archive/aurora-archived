// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_SHELL_LOG
#define INCLUDE_H_AURORA_SHELL_LOG

#include <Aurora/Lib/Output.h>
#include <Aurora/Lib/Target.h>
#include <Aurora/Shell/Output.h>
#include <Aurora/Core/Debug.h>
#include <Aurora/Core/Aurora.h>

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
        void Log (MessageStatus status, auto... args)
        {
            // TODO: Windows ANSI integration
            //       Needs to be tested on Windows and Apple platforms
            if(status == Error)
            {
                #ifdef AURORA_TARGET_UNIX
                std::cout << "\e[0m\e[1m[\e[1;31mERROR\e[0;1m] \e[0m";
                #else
                std::cout << "[ERROR] ";
                #endif
                Output(args...);
            }
            else if (status == Warning)
            {
                #ifdef AURORA_TARGET_UNIX
                std::cout << "\e[0m\e[1m[\e[1;33mWARNING\e[0;1m] \e[0m";
                #else
                std::cout << "[WARNING] ";
                #endif
                Output(args...);
            }
            else if (status == Notice)
            {
                #ifdef AURORA_TARGET_UNIX
                std::cout << "\e[0m\e[1m[\e[1;36mNOTICE\e[0;1m] \e[0m";
                #else
                std::cout << "[NOTICE] ";
                #endif
                Output(args...);
            }
            else if (status == Information)
            {
                #ifdef AURORA_TARGET_UNIX
                std::cout << "\e[0m\e[1m[\e[1;32mINFORMATION\e[0;1m] \e[0m";
                #else
                std::cout << "[INFORMATION] ";
                #endif
                Output(args...);
            }
            else if (status == Aurora::Shell::Debug)
            {
                if(Aurora::Debug::Status)
                {
                    #ifdef AURORA_TARGET_UNIX
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

#endif // INCLUDE_H_AURORA_SHELL_LOG