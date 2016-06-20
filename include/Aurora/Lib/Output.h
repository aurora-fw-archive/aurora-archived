// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_LIB_OUTPUT
#define INCLUDE_H_AURORA_LIB_OUTPUT 1

#include <Aurora/CORE/Aurora.h>
#include <Aurora/Lib/Target.h>

#ifdef AURORA_TARGET_CXX
#include <ostream>

namespace ar { namespace __ar {
        extern ostream cout;
        extern wostream wcout;
    }
    ostream out(nullptr);
    wostream w_out(nullptr);
    out.rdbuf(__ar::cout.rdbuf());
    w_out.rdbuf(__ar::wcout.rdbuf());

    template<typename _T, typename T> inline basic_ostream<_T, T>& endl(basic_ostream<_T, _T>& __os)
    { 
        return flush(__os.put(__os.widen('\n'))); 
    }
}
#endif // C++

#endif // INCLUDE_H_AURORA_LIB_OUTPUT