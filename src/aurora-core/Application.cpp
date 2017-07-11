// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <string>
#include <Aurora/Core/Application.h>
#include <Aurora/CLI/Log.h>
#include <Aurora/Core/Debug.h>

namespace Aurora
{
    Application::Application(void (*mainFunction)(), int argc, char *argv[])
    {
        ID = ( unsigned long ) Aurora::Debug::LastID;
        Aurora::Debug::LastID++;
        if(argc == 2)
        {
            if(std::string(argv[1]) == "--debug")
                Debug::enableDebug();
            else if(std::string(argv[1]) == "--verbose")
            {
                Debug::enableDebug(true);
                Debug::isVerbose = true;
            }
            else
                Debug::disableDebug(true);
        }
        Shell::Log(Shell::Debug, "creating new application: id_", ID);
        Shell::Log(Shell::Debug, "application id_", ID, " is created.");
        (*mainFunction)();
    }
    Application::~Application()
    {
        Shell::Log(Shell::Debug, "application id_", ID, " is destroyed.");
    }
    void Application::ExitSuccess()
    {
        Shell::Log(Shell::Debug, "application return success code: ", EXIT_SUCCESS);
        exit(EXIT_SUCCESS);
    }
    void Application::ExitFail()
    {
        Shell::Log(Shell::Debug, "application return error code: ", EXIT_FAILURE);
        exit(EXIT_FAILURE);
    }
}
