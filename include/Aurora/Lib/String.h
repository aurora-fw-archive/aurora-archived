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

#include <istream>
#include <ostream>

namespace Ar
{
    class String
    {
    public:
        String (const char* str = "");  // Normal string
        String (const String & str);    // String by copy
        int size();                     // Return String size
        ~String();

    private:
        char* buf;
        int len = 0;
    };
}

#endif // INCLUDE_H_AURORA_LIB_STRING