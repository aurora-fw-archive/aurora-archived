#ifndef _AURORA_GUIWINDOW
#define _AURORA_GUIWINDOW

#ifdef __linux__
#include <X11/Xlib.h>
#endif
#include <iostream>

#include <Aurora/Typedef.h>
#include <Aurora/GUIEvent.h>

struct GUIWindow
{
public:
    GUIWindow (std::string title = "Aurora Window",
               unsigned int width = 200, unsigned int height = 200,
               void (*mainFunction)() = []{});
    ~GUIWindow();
    
    void SetEvents(unsigned long ev);
    void SetTitle(std::string title);
    void SignalEvent(void (*signalEventFunction)(), int eventType);
    void StandardMain();
    
protected:
    //Display, Window and Event declarations
    #ifdef __linux__
    Display *XDisplay;
    Window XWindow;
    Window WindowParent;
    XEvent WindowEvent;
    #endif
    
    // Title Variable
    std::string WindowTitle;
    
    //Screen number variable
    int XScreen;
    
    //Window Size W/H
    unsigned int WindowWidth;
    unsigned int WindowHeight;
    
    //Initial X, Y Coordenates
    int WindowBorderX;
    int WindowBorderY;
    
    //Border Width size
    unsigned int WindowBorderWidth;
    
    //Border and Background colors : Default as Black and White
    unsigned long WindowBorder;
    unsigned long WindowBackground;

};

#endif // _AURORA_GUIWINDOW