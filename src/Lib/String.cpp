// "src/Lib/String.cpp" -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* Contains: String Class (Compatible with STL) */

/* TODO: Create Ar::String Normal and Conditional Operators:
**          Normal Operators:
**              =
**              +
**              +=
**          Conditional Operators:
**              ==
**              !=
**              >
**              <
**              <=
**              >=
*/

namespace Ar
{
    String::String(const char* str)
    {
        // Setting String Length
        while(str[len] != '\0')
            len++;
        
        /* Create the buffer with string
        ** length + '\0' char (end-of-string indicator) */
        buf = new char[len +1];
        for(int i=0; i<len; i++)
        {
            buf[i] = str[i];
        }
        // Add null character (end-of-string indicator)
        buf[len] = '\0';
    }

    String::~String()
    {

    }

    int String::size()
    {
        return len;
    }
}