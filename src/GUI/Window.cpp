#ifdef _WIN32
/// Windows API
#include <windows.h>
#else
/// X11 Library for X Server System
#include <X11/Xlib.h>
#endif

/// Library for Async Tasks (Multitasking & Multithreading)
#include <future>

///Aurora Framework Headers
#include <Aurora/ShellLog.h>
#include <Aurora/GUIWindow.h>
#include <Aurora/GUIEvent.h>

GUIWindow::GUIWindow (std::string title = "Aurora Window",
                      unsigned int width = 200, unsigned int height = 200)
{
    //Store window size
    WindowWidth = width;
    WindowHeight = height;
    
    //Open connection with the X Server
    XDisplay = XOpenDisplay(NULL);
    if (XDisplay == NULL)
    {
        ShellLog::Error("Can't open the display");
        return;
    }
    
    //Store some information
    XScreen = DefaultScreen(XDisplay);
    WindowParent = RootWindow(XDisplay, XScreen);
    WindowBorderX = 0;
    WindowBorderY = 0;
    WindowBorderWidth = 1;
    WindowBorder = BlackPixel(XDisplay, XScreen);
    WindowBackground = WhitePixel(XDisplay, XScreen);
    
    //Create the window
    XWindow = XCreateSimpleWindow(XDisplay, WindowParent, 
                                  WindowBorderX, WindowBorderY, 
                                  WindowWidth, WindowHeight, 
                                  WindowBorderWidth,
                                  WindowBorder, WindowBackground);
    
    // Select interested events
    SetEvents(GUIEventMask::None);
    
    // Show the window
    XMapWindow(XDisplay, XWindow);
    
    // Set the title
    SetTitle(title);
}

GUIWindow::~GUIWindow()
{
    XCloseDisplay(XDisplay);
}

void GUIWindow::SetEvents(unsigned long ev)
{
    XSelectInput(XDisplay, XWindow, ev);
}

void GUIWindow::LoopEvent(void (*signalEventFunction)(), int eventType)
{
    for(;;)
    {
        XNextEvent(XDisplay, &WindowEvent);
        if (event.type == eventType) (*signalEventFunction)();
    }
}

void GUIWindow::SignalEvent(void (*signalEventFunction)(), int eventType)
{
    std::async (LoopEvent, &signalEventFunction, eventType);
}

void GUIWindow::SetTitle(std::string title)
{
    XStoreName(XDisplay, XWindow, title.c_str());
}