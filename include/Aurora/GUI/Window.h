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

#include <Aurora/Common.h>

#ifndef INCLUDE_H_AURORA_GUI_WINDOW
#define INCLUDE_H_AURORA_GUI_WINDOW

#include <iostream>
#include <string>

typedef struct _GtkWidget GtkWidget;

namespace Aurora
{
	namespace GUI {
        class Window
    	{
    	friend class Label;
        friend class Button;
    	public:

    		// Window Types
    		enum WindowType
    		{
    			ToplevelWindow,
    			PopupWindow
    		};

    		// Window Positions
    		enum WindowPosition
    		{
    			NonePosition,
    			CenterPosition,
    			MousePosition,
    			AlwaysCenterPosition,
    			CenterParentPosition
    		};

    		Window(std::string = "Aurora Window", int = 200, int = 200, WindowPosition = NonePosition, WindowType = ToplevelWindow);
    		void setTitle(std::string );
    		void setPos(WindowPosition );
    		void connect(std::string , void (*)(), void* = NULL);
    		void show(void);
    		void start(void (*)() = []{});

    	protected:
    		GtkWidget *window;
    		const unsigned long ID;
    	};
    }
}

#endif // INCLUDE_H_AURORA_GUI_WINDOW
