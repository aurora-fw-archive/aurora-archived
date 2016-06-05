#ifndef _AURORA_GUIEVENT
#define _AURORA_GUIEVENT

namespace GUIEvent
{
    extern unsigned long EventNone; // No events wanted
    extern unsigned long EventKeyPress; // Keyboard down events wanted
    extern unsigned long EventKeyRelease; // Keyboard up events wanted
    extern unsigned long EventButtonPress; // Pointer button down events wanted
    extern unsigned long EventButtonRelease; // Pointer button up events wanted
    extern unsigned long EventEnterWindow; // Pointer window entry events wanted
    extern unsigned long EventLeaveWindow; // Pointer window leave events wanted
    extern unsigned long EventPointerMotion; // Pointer motion events wanted
    extern unsigned long EventPointerMotionHint; // Pointer motion hints wanted
    extern unsigned long EventButton1Motion; // Pointer motion while button 1 down
    extern unsigned long EventButton2Motion; // Pointer motion while button 2 down
    extern unsigned long EventButton3Motion; // Pointer motion while button 3 down
    extern unsigned long EventButton4Motion; // Pointer motion while button 4 down
    extern unsigned long EventButton5Motion; // Pointer motion while button 5 down
    extern unsigned long EventButtonMotion; // Pointer motion while any button down
    extern unsigned long EventKeymapState; // Keyboard state wanted at window entry and focus in
    extern unsigned long EventExposure; // Any exposure wanted
    extern unsigned long EventVisibilityChange; // Any change in visibility wanted
    extern unsigned long EventStructureNotify; // Any change in window structure wanted
    extern unsigned long EventResizeRedirect; // Redirect resize of this window
    extern unsigned long EventSubstructureNotify; // Substructure notification wanted
    extern unsigned long EventSubstructureRedirect; // Redirect structure requests on children
    extern unsigned long EventFocusChange; // Any change in input focus wanted
    extern unsigned long EventPropertyChange; // Any change in property wanted
    extern unsigned long EventColormapChange; // Any change in colormap wanted
    extern unsigned long EventOwnerGrabButton; // Automatic grabs should activate with owner_events set to True

    // Keyboard events
    extern int TypeKeyPress;
    extern int TypeKeyRelease;
    
    // Pointer events
    extern int TypeButtonPress;
    extern int TypeButtonRelease;
    extern int TypeMotionNotify;
    
    // Window crossing events
    extern int TypeEnterNotify;
    extern int TypeLeaveNotify;
    
    // Input focus events
    extern int TypeFocusIn;
    extern int TypeFocusOut;
    
    // Keymap state notification events
    extern int TypeKeymapNotify;
    
    // Exposure events
    extern int TypeExpose;
    extern int TypeGraphicsExpose;
    extern int TypeNoExpose;
    
    // Structure control events
    extern int TypeCirculateRequest;
    extern int TypeConfigureRequest;
    extern int TypeMapRequest;
    extern int TypeResizeRequest;
    
    // Window state notification
    extern int TypeCirculateNotify;
    extern int TypeConfigureNotify;
    extern int TypeCreateNotify;
    extern int TypeDestroyNotify;
    extern int TypeGravityNotify;
    extern int TypeMapNotify;
    extern int TypeMappingNotify;
    extern int TypeReparentNotify;
    extern int TypeUnmapNotify;
    extern int TypeVisibilityNotify;
    
    // Colormap state notification
    extern int TypeColormapNotify;
    
    // Client communication events
    extern int TypeClientMessage;
    extern int TypePropertyNotify;
    extern int TypeSelectionClear;
    extern int TypeSelectionNotify;
    extern int TypeSelectionRequest;
}

#endif // _AURORA_GUIEVENT