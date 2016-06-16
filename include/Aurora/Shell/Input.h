// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_SHELL_INPUT
#define _AURORA_SHELL_INPUT

#include <iostream>
#include <Aurora/Core/Macros.h>

namespace Aurora { namespace Shell
    {
        void Input (auto t);
        void Input (auto t, auto... args);
        void Input (auto t)
        {
            std::cin >> t;
        }

        void Input (auto t, auto... args)
        {
            std::cin >> t;
            Output(args...);
        }
    }
}

#endif // _AURORA_SHELL_INPUT