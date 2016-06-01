#ifndef _AURORA_GUIEVENT
#define _AURORA_GUIEVENT

namespace GUIEvent
{
    unsigned long EventNone; // No events wanted
    unsigned long EventKeyPress; // Keyboard down events wanted
    unsigned long EventKeyRelease; // Keyboard up events wanted
    unsigned long EventButtonPress; // Pointer button down events wanted
    unsigned long EventButtonRelease; // Pointer button up events wanted
    unsigned long EventEnterWindow; // Pointer window entry events wanted
    unsigned long EventLeaveWindow; // Pointer window leave events wanted
    unsigned long EventPointerMotion; // Pointer motion events wanted
    unsigned long EventPointerMotionHint; // Pointer motion hints wanted
    unsigned long EventButton1Motion; // Pointer motion while button 1 down
    unsigned long EventButton2Motion; // Pointer motion while button 2 down
    unsigned long EventButton3Motion; // Pointer motion while button 3 down
    unsigned long EventButton4Motion; // Pointer motion while button 4 down
    unsigned long EventButton5Motion; // Pointer motion while button 5 down
    unsigned long EventButtonMotion; // Pointer motion while any button down
    unsigned long EventKeymapState; // Keyboard state wanted at window entry and focus in
    unsigned long EventExposure; // Any exposure wanted
    unsigned long EventVisibilityChange; // Any change in visibility wanted
    unsigned long EventStructureNotify; // Any change in window structure wanted
    unsigned long EventResizeRedirect; // Redirect resize of this window
    unsigned long EventSubstructureNotify; // Substructure notification wanted
    unsigned long EventSubstructureRedirect; // Redirect structure requests on children
    unsigned long EventFocusChange; // Any change in input focus wanted
    unsigned long EventPropertyChange; // Any change in property wanted
    unsigned long EventColormapChange; // Any change in colormap wanted
    unsigned long EventOwnerGrabButton; // Automatic grabs should activate with owner_events set to True

    // Keyboard events
    int TypeKeyPress;
    int TypeKeyRelease;
    
    // Pointer events
    int TypeButtonPress;
    int TypeButtonRelease;
    int TypeMotionNotify;
    
    // Window crossing events
    int TypeEnterNotify;
    int TypeLeaveNotify;
    
    // Input focus events
    int TypeFocusIn;
    int TypeFocusOut;
    
    // Keymap state notification events
    int TypeKeymapNotify;
    
    // Exposure events
    int TypeExpose;
    int TypeGraphicsExpose;
    int TypeNoExpose;
    
    // Structure control events
    int TypeCirculateRequest;
    int TypeConfigureRequest;
    int TypeMapRequest;
    int TypeResizeRequest;
    
    // Window state notification
    int TypeCirculateNotify;
    int TypeConfigureNotify;
    int TypeCreateNotify;
    int TypeDestroyNotify;
    int TypeGravityNotify;
    int TypeMapNotify;
    int TypeMappingNotify;
    int TypeReparentNotify;
    int TypeUnmapNotify;
    int TypeVisibilityNotify;
    
    // Colormap state notification
    int TypeColormapNotify;
    
    // Client communication events
    int TypeClientMessage;
    int TypePropertyNotify;
    int TypeSelectionClear;
    int TypeSelectionNotify;
    int TypeSelectionRequest;
}

#endif // _AURORA_GUIEVENT