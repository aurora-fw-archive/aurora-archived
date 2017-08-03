// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <gtk/gtk.h>
#include <Aurora/GUI/Application.h>
#include <Aurora/Core/Debug.h>
#include <Aurora/CLI/Log.h>


namespace Aurora
{
	namespace GUI {
		Application::Application(std::string pkgname, ApplicationFlags flags, void (*mainfunction)(), int argc, char *argv[])
		{
			ID = ( unsigned long ) Aurora::Debug::LastID;
			Aurora::Debug::LastID++;
			if(argc == 2)
			{
				if((std::string(argv[1]) == "--debug") || (std::string(argv[1]) == "-D"))
				{
					Debug::enableDebug();
				}
				else if((std::string(argv[1]) == "--debug-silent") || (std::string(argv[1]) == "-Ds"))
				{
					Debug::enableDebug(true);
				}
				else if(std::string(argv[1]) == "--debug-log" || (std::string(argv[1]) == "-Dl"))
				{
					Debug::enableDebug();
					#define AURORA_DEBUG_LOG	1
				}
				else
				{
					Debug::disableDebug(true);
				}
			}
			Shell::Log(Shell::Debug, "creating new application: id_", ID);
			App = gtk_application_new (pkgname.c_str(), (GApplicationFlags)flags);
			Shell::Log(Shell::Debug, "application id_", ID, " is created.");
			connect("activate", mainfunction);
			AppStatus = g_application_run (G_APPLICATION (App), 0, NULL);
			g_object_unref(App);
		}

		void Application::connect(std::string detailedSignal, void (*signalFunction)(), void *signalData)
		{
			Shell::Log(Shell::Debug, "creating new signal on application id_", ID);
			g_signal_connect (App, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
		}
	}
}
