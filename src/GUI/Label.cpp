// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Gith

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
        if(Debug) ShellLog::Debug("creating new label: id_" + std::to_string(ID) + " on window id_" + std::to_string(parent->ID));
        Label = gtk_label_new (name.c_str());
        WindowParent = parent->Window;
        gtk_container_add(GTK_CONTAINER(WindowParent), Label);
        if(Debug) ShellLog::Debug("label id_" + std::to_string(ID) + " is created on window id_" + std::to_string(parent->ID));
        gtk_widget_show_all(WindowParent);
        if(Debug) ShellLog::Debug("showing label id_" + std::to_string(ID) + " on window id_" + std::to_string(parent->ID));
    }
    void GUILabel::setText(std::string text)
    {
        if(Debug) ShellLog::Debug("setting text on label id_" + std::to_string(ID));
        gtk_label_set_text((GtkLabel*)Label, text.c_str());
    }
}