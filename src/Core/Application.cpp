// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <string>
#include <Aurora/Core/Application.h>
#include <Aurora/Core/Macros.h>
#include <Aurora/Shell/Log.h>
#include <Aurora/Core/Debug.h>

namespace Aurora
{
    Application::Application(void (*mainFunction)(), int argc, char *argv[])
    {
        ID = ( unsigned long ) Aurora::LastID;
        Aurora::LastID++;
        if(argc == 2)
        {
            if((std::string(argv[1]) == "--debug") || (std::string(argv[1]) == "-ds"))
            {
                enableDebug();
            }
            else if((std::string(argv[1]) == "--debug-silent") || (std::string(argv[1]) == "-ds"))
            {
                enableDebug(true);
            }
            else
            {
                disableDebug(true);
            }
        }
        ShellLog::Debug("creating new application: id_" + std::to_string(ID));
        ShellLog::Debug("application id_" + std::to_string(ID) + " is created.");
        (*mainFunction)();
    }
    Application::~Application()
    {
        ShellLog::Debug("application id_" + std::to_string(ID) + " is destroyed.");
    }
    void Application::ExitSuccess()
    {
        ShellLog::Debug("application return success code: " + std::to_string(EXIT_SUCCESS));
        exit(EXIT_SUCCESS);
    }
    void Application::ExitFail()
    {
        ShellLog::Debug("application return error code: " + std::to_string(EXIT_FAILURE));
        exit(EXIT_FAILURE);
    }
}