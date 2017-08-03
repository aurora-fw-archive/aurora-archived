// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef INCLUDE_H_AURORA_GUI_APPLICATION
#define INCLUDE_H_AURORA_GUI_APPLICATION

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#include <iostream>

typedef struct _GtkApplication GtkApplication;

namespace Aurora
{
    namespace GUI {
        class Application
        {
        public:
            enum ApplicationFlags
            {
                NoneFlag,
                ServiceFlag,
                LauncherFlag,
                HandlesOpenFlag,
                HandlesCommandLineFlag,
                SendEnvironmentFlag,
                NonUniqueFlag,
                OverrideAppIDFlag
            };
            Application(std::string pkgname = "org.aurora.example", ApplicationFlags flags = NoneFlag, void (*mainfunction)() = []{}, int argc = 0, char *argv[] = NULL);
            ~Application();
            void connect(std::string detailedSignal, void (*signalFunction)(), void *signalData = NULL);
            int AppStatus;

        protected:
            GtkApplication *App;
            unsigned long ID = 0;
        };
    }
}

#endif // INCLUDE_H_AURORA_GUI_APPLICATION
