// <Aurora/Lib/String.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* Contains: String Class (Compatible with STL) */

#ifndef INCLUDE_H_AURORA_LIB_STRING
#define INCLUDE_H_AURORA_LIB_STRING    1

#pragma once

#include <Aurora/Lib/Target.h>

#ifdef AURORA_TARGET_CXX
#include <istream>
#include <ostream>
#endif

namespace Ar
{
    template<class charT>
    class __string
    {
    public:
        __string();                                     //Blank string
        __string (const charT* );                        // Normal string
        __string (const __string<charT> & );              // String by copy
        ~__string();

        //Operators
        __string& operator = (const __string<charT> & );   // Operator: =
        __string operator + (const __string<charT> & );         // Operator: +
        __string& operator += (const __string<charT> & );        // Operator: +=
        inline charT& operator [] (const int ) const;        // Operator: []

        inline void output (std::ostream & );
        inline void output (std::wostream & );
        void input (std::istream & );
        void input (std::wistream & );
        inline int size() const;                    // Return String size

    protected:
        charT* _buf = NULL;
    };
    typedef __string<char>      String;
    typedef __string<wchar_t>   wString;

    extern std::ostream & operator << (std::ostream &_out, String &__str);
    extern std::istream & operator >> (std::istream &_in, String &__str);

    //for wide characters
    extern std::wostream & operator << (std::wostream &_wout, wString &__wstr);
    extern std::wistream & operator >> (std::wistream &_win, wString &__wstr);
}

#ifndef AURORA_STRING_MAXSIZE
    #ifdef __AURORA_WORDSIZE
        #if __AURORA_WORDSIZE == 64
            #define AURORA_STRING_MAXSIZE   9223372036854775807
        #else
            #define AURORA_STRING_MAXSIZE   2147483647
        #endif
    #endif
#endif

#endif // INCLUDE_H_AURORA_LIB_STRING