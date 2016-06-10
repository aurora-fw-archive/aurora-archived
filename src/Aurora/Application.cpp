// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <Aurora/Application.h>
#include <Aurora/Macros.h>

AuroraApplication::AuroraApplication(void (*mainFucntion)(), int argc, char *argv[])
{
    if(argc == 2)
    {
        if((std::string(argv[1]) == "--debug") || (std::string(argv[1]) == "-D"))
        {
            Aurora::Debug = true;
        }
        else
        {
            Aurora::Debug = false;
        }
    }
    (*mainFucntion)();
}

AuroraApplication::~AuroraApplication()
{
    exit(0);
}