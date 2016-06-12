// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_SHELL_COLOR
#define _AURORA_SHELL_COLOR

#include <Aurora/Shell/ColorType.h>

namespace Aurora
{
    namespace Shell
    {
        enum class Color : unsigned int {
            Black,
            Blue,
            Green,
            Cyan,
            Red,
            Magenta,
            Yellow,
            LightGrey,
            DarkGrey,
            LightBlue,
            LightGreen,
            LightCyan,
            LightRed,
            LightMagenta,
            LightYellow,
            White
        };
        extern void setColor(Color color, ColorType type = ColorType::Foreground);
        extern void resetColor();
    };
}

#endif // _AURORA_SHELL_COLOR