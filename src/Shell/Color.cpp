// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/ShellColor.h>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif


namespace AuroraShell
{
    unsigned int Color::Black(ColorType type)
    {   
        #ifdef _WIN32
        if (!(type == ColorType::Return))
        {
            if(type == ColorType::Background)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLACK);
            else if(type == ColorType::Foreground)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLACK);
            else if(type == ColorType::Both)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLACK | BACKGROUND_BLACK);
        }
        #elif __unix__
        if (!(type == ColorType::Return))
        {
            if(type == ColorType::Background)
                std::cout << "\e[40m";
            else if(type == ColorType::Foreground)
                std::cout << "\e[30m";
            else if(type == ColorType::Both)
                std::cout << "\e[30;40m";
        }
        #endif
        return 0x0;
    }
}