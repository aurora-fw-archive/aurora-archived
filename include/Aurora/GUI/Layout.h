// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_GUI_LAYOUT
#define INCLUDE_H_AURORA_GUI_LAYOUT 

#include <Aurora/Core/Aurora.h>

namespace Aurora
{
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

#endif // INCLUDE_H_AURORA_GUI_LAYOUT