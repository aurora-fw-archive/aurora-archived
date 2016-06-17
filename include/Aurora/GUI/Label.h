// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef INCLUDE_H_AURORA_GUI_LABEL
#define INCLUDE_H_AURORA_GUI_LABEL

#include <Aurora/GUI/Window.h>
#include <Aurora/Core/Aurora.h>

typedef struct _GtkWidget GtkWidget;

namespace Aurora
{
    class GUILabel
    {
    public:
        GUILabel(GUIWindow *parent, std::string name = "New Label");
        void setText(std::string text);
        std::string getText();
        void setSelectable(bool value);
        bool getSelectable();

    private:
        unsigned long ID = 0;
        GtkWidget *Label;
        GtkWidget *WindowParent;
    };
}

#endif // INCLUDE_H_AURORA_GUI_LABEL