// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_LIB_INPUT
#define INCLUDE_H_AURORA_LIB_INPUT  1

#include <Aurora/Core/Aurora.h>
#include <Aurora/Lib/Target.h>

#ifdef AURORA_TARGET_CXX
#include <istream>
namespace ar { namespace __ar { 
        extern istream cin;
        extern wistream wcin;
    }
    istream in(nullptr);
    wistream w_in(nullptr);
    in.rdbuf(__ar::cin.rdbuf());
    w_in.rdbuf(__ar::wcin.rdbuf());
}
#endif // C++

#endif // INCLUDE_H_AURORA_LIB_INPUT