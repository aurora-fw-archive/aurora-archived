#ifndef _AURORA_GUIWINDOW
#define _AURORA_GUIWINDOW

extern struct Display;
extern struct Window;
extern struct XEvent;

struct GUIWindow
{
public:
    GUIWindow (std::string title, unsigned int width, unsigned int height);
    ~GUIWindow();
    
    void SetEvents(unsigned long ev);
    void SetTitle(std::string title);
    void SignalEvent(void (*signalEventFunction)(), int eventType);
    
protected:
    //Display, Window and Event declarations
    Display *XDisplay;
    Window XWindow;
    Window WindowParent;
    XEvent WindowEvent;
    
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

private:
    void LoopEvent(void (*signalEventFunction)(), int eventType);
};

#endif // _AURORA_GUIWINDOW