// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <string>
#include <Aurora/Core/Application.h>
#include <Aurora/Shell/Log.hpp>
#include <Aurora/Core/Debug.h>

namespace Aurora
{
    Application::Application(void (*mainFunction)(), int argc, char *argv[])
    {
        ID = ( unsigned long ) Aurora::Debug::LastID;
        Aurora::Debug::LastID++;
        if(argc == 2)
        {
            if((std::string(argv[1]) == "--debug") || (std::string(argv[1]) == "-ds"))
            {
                Debug::enableDebug();
            }
            else if((std::string(argv[1]) == "--debug-silent") || (std::string(argv[1]) == "-ds"))
            {
                Debug::enableDebug(true);
            }
            else
            {
                Debug::disableDebug(true);
            }
        }
        Shell::Log(Shell::Debug, "creating new application: id_", ID, Shell::EndLine);
        Shell::Log(Shell::Debug, "application id_", ID, " is created.", Shell::EndLine);
        (*mainFunction)();
    }
    Application::~Application()
    {
        Shell::Log(Shell::Debug, "application id_", ID, " is destroyed.", Shell::EndLine);
    }
    void Application::ExitSuccess()
    {
        Shell::Log(Shell::Debug, "application return success code: ", EXIT_SUCCESS, Shell::EndLine);
        exit(EXIT_SUCCESS);
    }
    void Application::ExitFail()
    {
        Shell::Log(Shell::Debug, "application return error code: ", EXIT_FAILURE, Shell::EndLine);
        exit(EXIT_FAILURE);
    }
}
