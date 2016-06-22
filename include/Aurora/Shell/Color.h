// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_SHELL_COLOR
#define INCLUDE_H_AURORA_SHELL_COLOR

#include <Aurora/Core/Aurora.h>

namespace Aurora
{
    namespace Shell
    {
        enum class ColorType
        {
            Background,
            Foreground
        };

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

#endif // INCLUDE_H_AURORA_SHELL_COLOR