// <Aurora/GUI/Window.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/aurora-fw/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#ifndef INCLUDE_H_AURORA_GUI_LAYOUT
#define INCLUDE_H_AURORA_GUI_LAYOUT

namespace Aurora
{
	namespace GUI {
        enum class WrapMode
    	{
    		Word,
    		Char,
    		WordChar
    	};
    	enum class AlignMode
    	{
    		/* TL  TC  TR	| \ | /
    		** L   C   R	| < * >
    		** BL  BC  BR	| / | \
    		*/
    		TopLeft,
    		TopCenter,
    		TopRight,
    		Left,
    		Center,
    		Right,
    		BottomLeft,
    		BottomCenter,
    		BottomRight,
    		Custom
    	};
    	enum class JustifyMode
    	{
    		Left,
    		Right,
    		Center,
    		Fill
    	};
    }
}

#endif // INCLUDE_H_AURORA_GUI_LAYOUT
