// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_GUI_STYLE
#define _AURORA_GUI_STYLE

#include <Aurora/Core/Typedef.h>

namespace Aurora 
{
    namespace GUIStyle
    {
        ///Warp Mode
        // wrap lines at word boundaries.
        static const arflags_t WarpWord;
        // wrap lines at character boundaries.
        static const arflags_t WarpChar;
        /* wrap lines at word boundaries, but fall back to character
        * boundaries if there is not enough space for a full word. */
        static const arflags_t WarpWordChar;

        
    }
}

#endif // _AURORA_GUI_STYLE