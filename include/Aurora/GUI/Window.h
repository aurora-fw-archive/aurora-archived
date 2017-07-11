// <Aurora/GUI/Window.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

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

#ifndef INCLUDE_H_AURORA_GUI_WINDOW
#define INCLUDE_H_AURORA_GUI_WINDOW

#include <iostream>
#include <string>

typedef struct _GtkWidget GtkWidget;

namespace Aurora
{
	class GUIWindow
	{
	friend class GUILabel;
	public:

		// Window Types
		enum GUIWindowType
		{
			ToplevelWindow,
			PopupWindow
		};

		// Window Positions
		enum GUIWindowPosition
		{
			NonePosition,
			CenterPosition,
			MousePosition,
			AlwaysCenterPosition,
			CenterParentPosition
		};

		GUIWindow(std::string name = "Aurora Window", int width = 200, int height = 200, GUIWindowPosition pos = NonePosition, GUIWindowType type = ToplevelWindow);
		void setTitle(std::string title);
		void setPos(GUIWindowPosition pos);
		void connect(std::string detailedSignal, void (*signalFunction)(), void* signalData = NULL);
		void show(void);
		void start(void (*startFunction)() = []{});

	protected:
		GtkWidget *Window;
		unsigned long ID = 0;
	};
}

#endif // INCLUDE_H_AURORA_GUI_WINDOW
