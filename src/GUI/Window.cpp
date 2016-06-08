// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <gtk/gtk.h>
#include <Aurora/GUIWindow.h>

//Window Types
const arflags_t GUIWindow::ToplevelWindow = GTK_WINDOW_TOPLEVEL;
const arflags_t GUIWindow::PopupWindow = GTK_WINDOW_POPUP;

//Window Positions
const arflags_t GUIWindow::NonePosition = GTK_WIN_POS_NONE;
const arflags_t GUIWindow::CenterPosition = GTK_WIN_POS_CENTER;
const arflags_t GUIWindow::MousePosition = GTK_WIN_POS_MOUSE;
const arflags_t GUIWindow::AlwaysCenterPosition = GTK_WIN_POS_CENTER_ALWAYS;
const arflags_t GUIWindow::CenterParentPosition = GTK_WIN_POS_CENTER_ON_PARENT;

GUIWindow::GUIWindow(std::string name, int width, int height, int pos, arflags_t type)
{
    Window = gtk_window_new((GtkWindowType) type);
    setTitle(name);
    setPos(pos);
    gtk_window_set_default_size(GTK_WINDOW(Window), width, height);
    connect("destroy", gtk_main_quit);
    show();
}

void GUIWindow::setTitle(std::string title) 
{
    gtk_window_set_title(GTK_WINDOW(Window), title.c_str());
}

void GUIWindow::setPos(int pos)
{
    gtk_window_set_position (GTK_WINDOW(Window), (GtkWindowPosition) pos);
}

void GUIWindow::connect(std::string detailedSignal, void (*signalFunction)(), void* signalData)
{
    g_signal_connect(Window, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
}

void GUIWindow::show(void)
{
    gtk_widget_show_all(Window);
}

void GUIWindow::start(void)
{
    gtk_main();
}