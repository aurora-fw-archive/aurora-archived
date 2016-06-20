// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_SHELL_OUTPUT
#define INCLUDE_H_AURORA_SHELL_OUTPUT

#include <Aurora/Lib/Output.h>
#include <Aurora/Core/Aurora.h>

namespace Aurora { namespace Shell
    {
        void Output (auto t);
        void Output (auto t, auto... args);
        void Output (auto t)
        {
            ar::out << t;
        }

        void Output (auto t, auto... args)
        {
            ar::out << t;
            Output(args...);
        }
    }
}

#endif // INCLUDE_H_AURORA_SHELL_OUTPUT