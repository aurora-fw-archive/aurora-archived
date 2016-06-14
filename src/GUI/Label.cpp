// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <gtk/gtk.h>

#include <Aurora/GUI/Label.h>
#include <Aurora/GUI/Window.h>
#include <Aurora/Shell/Log.h>
#include <Aurora/Core/Macros.h>
#include <Aurora/Core/Debug.h>

namespace Aurora
{
    GUILabel::GUILabel(GUIWindow *parent, std::string name)
    {
        ID = (unsigned)(long) Aurora::LastID;
        Aurora::LastID++;
        ShellLog::Debug("creating new label: id_" + std::to_string(ID) + " on window id_" + std::to_string(parent->ID));
        Label = gtk_label_new (name.c_str());
        WindowParent = parent->Window;
        gtk_container_add(GTK_CONTAINER(WindowParent), Label);
        ShellLog::Debug("label id_" + std::to_string(ID) + " is created on window id_" + std::to_string(parent->ID));
        gtk_widget_show_all(WindowParent);
        ShellLog::Debug("showing label id_" + std::to_string(ID) + " on window id_" + std::to_string(parent->ID));
    }

    //Settings
    void GUILabel::setText(std::string text)
    {
        ShellLog::Debug("setting text on label id_" + std::to_string(ID));
        gtk_label_set_text((GtkLabel*)Label, text.c_str());
    }
    std::string GUILabel::getText()
    {
        ShellLog::Debug("getting text from label id_" + std::to_string(ID));
        return std::string(gtk_label_get_text ((GtkLabel*)Label));
    }
    void GUILabel::setSelectable(bool value)
    {
        ShellLog::Debug("setting selectable property on label id_" + std::to_string(ID));
        gtk_label_set_selectable((GtkLabel*)Label, value);
    }
    bool GUILabel::getSelectable()
    {
        ShellLog::Debug("getting selectable property from label id_" + std::to_string(ID));
        return gtk_label_get_selectable((GtkLabel*)Label);
    }

}