// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_GUI_LABEL
#define _AURORA_GUI_LABEL

#include <Aurora/GUI/Window.h>

typedef struct _GtkWidget GtkWidget;

namespace Aurora
{
    class GUILabel
    {
    public:
        GUILabel(GUIWindow *parent, std::string name = "New Label");
        void setText(std::string text);

    private:
        unsigned long ID = 0;
        GtkWidget *Label;
        GtkWidget *WindowParent;
    };
}

#endif // _AURORA_GUI_LABEL