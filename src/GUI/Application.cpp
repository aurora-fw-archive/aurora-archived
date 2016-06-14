// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <iostream>
#include <gtk/gtk.h>
#include <Aurora/GUI/Application.h>
#include <Aurora/Core/Debug.h>
#include <Aurora/Core/Macros.h>
#include <Aurora/Shell/Log.h>
#include <Aurora/Core/Debug.h>

namespace Aurora
{
    // Application Flags
    const arflags_t GUIApplication::NoneFlag = G_APPLICATION_FLAGS_NONE;
    const arflags_t GUIApplication::ServiceFlag = G_APPLICATION_IS_SERVICE;
    const arflags_t GUIApplication::LauncherFlag = G_APPLICATION_IS_LAUNCHER;
    const arflags_t GUIApplication::HandlesOpenFlag = G_APPLICATION_HANDLES_OPEN;
    const arflags_t GUIApplication::HandlesCommandLineFlag = G_APPLICATION_HANDLES_COMMAND_LINE;
    const arflags_t GUIApplication::SendEnvironmentFlag = G_APPLICATION_SEND_ENVIRONMENT;
    const arflags_t GUIApplication::NonUniqueFlag = G_APPLICATION_NON_UNIQUE;
    const arflags_t GUIApplication::OverrideAppIDFlag = G_APPLICATION_CAN_OVERRIDE_APP_ID;

    GUIApplication::GUIApplication(std::string pkgname, arflags_t flags, void (*mainfunction)(), int argc, char *argv[])
    {
        ID = ( unsigned long ) Aurora::LastID;
        Aurora::LastID++;
        if(argc == 2)
        {
            if((std::string(argv[1]) == "--debug") || (std::string(argv[1]) == "-ds"))
            {
                enableDebug();
            }
            else if((std::string(argv[1]) == "--debug-silent") || (std::string(argv[1]) == "-ds"))
            {
                enableDebug(true);
            }
            else
            {
                disableDebug(true);
            }
        }
        ShellLog::Debug("creating new application: id_" + std::to_string(ID));
        App = gtk_application_new (pkgname.c_str(), (GApplicationFlags) flags);
        ShellLog::Debug("application id_" + std::to_string(ID) + " is created.");
        connect("activate", mainfunction);
        AppStatus = g_application_run (G_APPLICATION (App), 0, NULL);
        g_object_unref(App);
    }

    void GUIApplication::connect(std::string detailedSignal, void (*signalFunction)(), void *signalData)
    {
        ShellLog::Debug("creating new signal on application id_" + std::to_string(ID));
        g_signal_connect (App, detailedSignal.c_str(), G_CALLBACK(signalFunction), signalData);
    }
}