// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <gtk/gtk.h>
#include <Aurora/GUIApplication.h>

// Application Flags
const arflags_t GUIApplication::NoneFlag = G_APPLICATION_FLAGS_NONE;
const arflags_t GUIApplication::ServiceFlag = G_APPLICATION_IS_SERVICE;
const arflags_t GUIApplication::LauncherFlag = G_APPLICATION_IS_LAUNCHER;
const arflags_t GUIApplication::HandlesOpenFlag = G_APPLICATION_HANDLES_OPEN;
const arflags_t GUIApplication::HandlesCommandLineFlag =G_APPLICATION_HANDLES_COMMAND_LINE;
const arflags_t GUIApplication::SendEnvironmentFlag = G_APPLICATION_SEND_ENVIRONMENT;
const arflags_t GUIApplication::NonUniqueFlag = G_APPLICATION_NON_UNIQUE;
const arflags_t GUIApplication::OverrideAppIDFlag = G_APPLICATION_CAN_OVERRIDE_APP_ID;

GUIApplication::GUIApplication(std::string pkgname, arflags_t flags, void (*mainfunction)(), int argc, char *argv[])
{
    App = gtk_application_new (pkgname.c_str(), (GApplicationFlags) flags);
    g_signal_connect (App, "activate", G_CALLBACK(mainfunction), NULL);
    AppStatus = g_application_run (G_APPLICATION (App), argc, argv);
    g_object_unref(App);
}