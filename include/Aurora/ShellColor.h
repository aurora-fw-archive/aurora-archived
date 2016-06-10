// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_SHELLCOLOR
#define _AURORA_SHELLCOLOR

namespace AuroraShell
{
    enum class ColorType
    {
        Background,
        Foreground,
        Both,
        Return
    };
    struct Color
    {
        static unsigned int Black(ColorType type = ColorType::Return);
        static unsigned int Blue(ColorType type = ColorType::Return);
        static unsigned int Green(ColorType type = ColorType::Return);
        static unsigned int Cyan(ColorType type = ColorType::Return);
        static unsigned int Red(ColorType type = ColorType::Return);
        static unsigned int Magenta(ColorType type = ColorType::Return);
        static unsigned int Yellow(ColorType type = ColorType::Return);
        static unsigned int LightGrey(ColorType type = ColorType::Return);
        static unsigned int DarkGrey(ColorType type = ColorType::Return);
        static unsigned int LightBlue(ColorType type = ColorType::Return);
        static unsigned int LightGreen(ColorType type = ColorType::Return);
        static unsigned int LightCyan(ColorType type = ColorType::Return);
        static unsigned int LightRed(ColorType type = ColorType::Return);
        static unsigned int LightMagenta(ColorType type = ColorType::Return);
        static unsigned int White(ColorType type = ColorType::Return);
        static unsigned int Reset(ColorType type = ColorType::Return);
    };
}

#endif // _AURORA_SHELLCOLOR