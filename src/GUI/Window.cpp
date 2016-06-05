#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <X11/Xlib.h>
#else
#include <gtk/gtk.h>
#endif
#include <Aurora/ShellLog.h>
#include <Aurora/GUIWindow.h>
#include <Aurora/GUIEvent.h>

namespace AuroraMacros {
    extern bool Debug;
}


GUIWindow::GUIWindow (std::string title,
                      unsigned int width, unsigned int height,
                      void (*mainFunction)())
{
    //Store window size
    WindowWidth = width;
    WindowHeight = height;
    
    WindowBorderX = 0;
    WindowBorderY = 0;
    WindowBorderWidth = 1;
    
    
    #ifdef __linux__
    //Open connection with the X Server
    if(AuroraMacros::Debug) AuroraShell::Log::Information("Opening connection with the X Server");
    XDisplay = XOpenDisplay(NULL);
    if (XDisplay == NULL)
    {
        AuroraShell::Log::Error("Can't open the display");
        return;
    }
    //Connected message
    if(AuroraMacros::Debug) AuroraShell::Log::Information("Connected with the X Server");
    
    //Store some information
    XScreen = DefaultScreen(XDisplay);
    WindowParent = RootWindow(XDisplay, XScreen);
    WindowBorder = BlackPixel(XDisplay, XScreen);
    WindowBackground = WhitePixel(XDisplay, XScreen);
    
    //Create the window
    if(AuroraMacros::Debug) AuroraShell::Log::Information("Creating the window...");
    XWindow = XCreateSimpleWindow(XDisplay, WindowParent, 
                                  WindowBorderX, WindowBorderY, 
                                  WindowWidth, WindowHeight, 
                                  WindowBorderWidth,
                                  WindowBorder, WindowBackground);
    #endif
    
    // Select interested events
    SetEvents(GUIEvent::EventExposure);
    
    #ifdef __linux__
    // Show the window
    XMapWindow(XDisplay, XWindow);
    #endif
    
    // Set the title
    SetTitle(title);

    SignalEvent(mainFunction, GUIEvent::TypeExpose);
}

GUIWindow::~GUIWindow()
{
    #ifdef __linux__
    XCloseDisplay(XDisplay);
    #endif
}

void GUIWindow::SetEvents(unsigned long ev)
{
    XSelectInput(XDisplay, XWindow, ev);
}

void GUIWindow::SignalEvent(void (*signalEventFunction)(), int eventType)
{
    for(;;)
    {
        while (XPending(XDisplay))
        {
            XNextEvent(XDisplay, &WindowEvent);
            if (WindowEvent.type == eventType) 
            {
                (*signalEventFunction)();
            }
        }
    }
}

void GUIWindow::SetTitle(std::string title)
{
    XStoreName(XDisplay, XWindow, title.c_str());
}