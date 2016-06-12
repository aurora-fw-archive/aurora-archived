// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#ifndef _AURORA_GUI_APPLICATION
#define _AURORA_GUI_APPLICATION

#include <iostream>
#include <Aurora/Core/Typedef.h>

typedef struct _GtkApplication GtkApplication;

namespace Aurora
{
    class GUIApplication
    {
    public:
        //Application Flags
        static const arflags_t NoneFlag;
        static const arflags_t ServiceFlag;
        static const arflags_t LauncherFlag;
        static const arflags_t HandlesOpenFlag;
        static const arflags_t HandlesCommandLineFlag;
        static const arflags_t SendEnvironmentFlag;
        static const arflags_t NonUniqueFlag;
        static const arflags_t OverrideAppIDFlag;

        GUIApplication(std::string pkgname = "org.aurora.example", arflags_t flags = NoneFlag, void (*mainfunction)() = []{}, int argc = 0, char *argv[] = NULL);
        void connect(std::string detailedSignal, void (*signalFunction)(), void *signalData = NULL);
        int AppStatus;

    private:
        GtkApplication *App;
        unsigned long ID = 0;
    };
}

#endif // _AURORA_GUI_APPLICATION