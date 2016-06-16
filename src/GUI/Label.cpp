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
        Shell::Log(Shell::Debug, "creating new label: id_", ID, " on window id_", parent->ID, Shell::EndLine);
        Label = gtk_label_new (name.c_str());
        WindowParent = parent->Window;
        gtk_container_add(GTK_CONTAINER(WindowParent), Label);
        Shell::Log(Shell::Debug, "label id_", ID, " is created on window id_", parent->ID, Shell::EndLine);
        gtk_widget_show_all(WindowParent);
        Shell::Log(Shell::Debug, "showing label id_", ID, " on window id_", parent->ID, Shell::EndLine);
    }

    //Settings
    void GUILabel::setText(std::string text)
    {
        Shell::Log(Shell::Debug, "setting text on label id_", ID, Shell::EndLine);
        gtk_label_set_text((GtkLabel*)Label, text.c_str());
    }
    std::string GUILabel::getText()
    {
        Shell::Log(Shell::Debug, "getting text from label id_", ID, Shell::EndLine);
        return std::string(gtk_label_get_text ((GtkLabel*)Label));
    }
    void GUILabel::setSelectable(bool value)
    {
        Shell::Log(Shell::Debug, "setting selectable property on label id_", ID, Shell::EndLine);
        gtk_label_set_selectable((GtkLabel*)Label, value);
    }
    bool GUILabel::getSelectable()
    {
        Shell::Log(Shell::Debug, "getting selectable property from label id_", ID, Shell::EndLine);
        return gtk_label_get_selectable((GtkLabel*)Label);
    }

}