// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <gtk/gtk.h>
#include <Aurora/GUI/Window.h>
#include <Aurora/Core/Debug.h>
#include <Aurora/CLI/Log.h>

namespace Aurora
{
	GUIWindow::GUIWindow(std::string name, int width, int height, GUIWindowPosition pos, GUIWindowType type)
	{
		ID = ( unsigned long ) Aurora::Debug::LastID;
		static const unsigned long scid_tmp = ID;
		Aurora::Debug::LastID++;
		Shell::Log(Shell::Debug, "creating new window: id_", ID);
		Window = gtk_window_new((GtkWindowType)type);
		setTitle(name);
		setPos(pos);
		gtk_window_set_default_size(GTK_WINDOW(Window), width, height);
		connect("destroy", []{
			gtk_main_quit();
			Shell::Log(Shell::Debug, "window id_", scid_tmp, " is destroyed.");
		});
		show();
		Shell::Log(Shell::Debug, "window id_", ID, " is created.");
	}

	void GUIWindow::setTitle(std::string title)
	{
		Shell::Log(Shell::Debug, "setting title on window id_", ID);
		gtk_window_set_title(GTK_WINDOW(Window), title.c_str());
	}

	void GUIWindow::setPos(GUIWindowPosition pos)
	{
		Shell::Log(Shell::Debug, "setting window position on window id_", ID);
		gtk_window_set_position (GTK_WINDOW(Window), (GtkWindowPosition) pos);
	}

	void GUIWindow::connect(std::string detailedSignal, void (*signalFunction)(), void* signalData)
	{
		Shell::Log(Shell::Debug, "creating new signal on window id_", ID);
		g_signal_connect(Window, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
	}

	void GUIWindow::show(void)
	{
		Shell::Log(Shell::Debug, "show window id_", ID);
		gtk_widget_show_all(Window);
	}

	void GUIWindow::start(void (*startFunction)())
	{
		(*startFunction)();
		Shell::Log(Shell::Debug, "starting main loop on window id_", ID);
		gtk_main();
	}
}
