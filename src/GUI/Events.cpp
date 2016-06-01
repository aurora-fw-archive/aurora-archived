#include <X11/Xlib.h>
#include <Aurora/GUIEvent.h>

namespace GUIEvent
{
    EventNone = NoEventMask; // No events wanted
    EventKeyPress = KeyPressMask; // Keyboard down events wanted
    EventKeyRelease = KeyReleaseMask; // Keyboard up events wanted
    EventButtonPress = ButtonPressMask; // Pointer button down events wanted
    EventButtonRelease = ButtonReleaseMask; // Pointer button up events wanted
    EventEnterWindow = EnterWindowMask; // Pointer window entry events wanted
    EventLeaveWindow = LeaveWindowMask; // Pointer window leave events wanted
    EventPointerMotion = PointerMotionMask; // Pointer motion events wanted
    EventPointerMotionHint = PointerMotionHintMask; // Pointer motion hints wanted
    EventButton1Motion = Button1MotionMask; // Pointer motion while button 1 down
    EventButton2Motion = Button2MotionMask; // Pointer motion while button 2 down
    EventButton3Motion = Button3MotionMask; // Pointer motion while button 3 down
    EventButton4Motion = Button4MotionMask; // Pointer motion while button 4 down
    EventButton5Motion = Button5MotionMask; // Pointer motion while button 5 down
    EventButtonMotion = ButtonMotionMask; // Pointer motion while any button down
    EventKeymapState = KeymapStateMask; // Keyboard state wanted at window entry and focus in
    EventExposure = ExposureMask; // Any exposure wanted
    EventVisibilityChange = VisibilityChangeMask; // Any change in visibility wanted
    EventStructureNotify = StructureNotifyMask; // Any change in window structure wanted
    EventResizeRedirect = ResizeRedirectMask; // Redirect resize of this window
    EventSubstructureNotify = SubstructureNotifyMask; // Substructure notification wanted
    EventSubstructureRedirect = SubstructureRedirectMask; // Redirect structure requests on children
    EventFocusChange = FocusChangeMask; // Any change in input focus wanted
    EventPropertyChange = PropertyChangeMask; // Any change in property wanted
    EventColormapChange = ColormapChangeMask; // Any change in colormap wanted
    EventOwnerGrabButton = OwnerGrabButtonMask; // Automatic grabs should activate with owner_events set to True
    
    // Keyboard events
    TypeKeyPress = KeyPress;
    TypeKeyRelease = KeyRelease;
    
    // Pointer events
    TypeButtonPress = ButtonPress;
    TypeButtonRelease = ButtonRelease;
    TypeMotionNotify = MotionNotify;
    
    // Window crossing events
    TypeEnterNotify = EnterNotify;
    TypeLeaveNotify = LeaveNotify;
    
    // Input focus events
    TypeFocusIn = FocusIn;
    TypeFocusOut = FocusOut;
    
    // Keymap state notification events
    TypeKeymapNotify = KeymapNotify;
    
    // Exposure events
    TypeExpose = Expose;
    TypeGraphicsExpose = GraphicsExpose;
    TypeNoExpose = NoExpose;
    
    // Structure control events
    TypeCirculateRequest = CirculateRequest;
    TypeConfigureRequest = ConfigureRequest;
    TypeMapRequest = MapRequest;
    TypeResizeRequest = ResizeRequest;
    
    // Window state notification
    TypeCirculateNotify = CirculateNotify;
    TypeConfigureNotify = ConfigureNotify;
    TypeCreateNotify = CreateNotify;
    TypeDestroyNotify = DestroyNotify;
    TypeGravityNotify = GravityNotify;
    TypeMapNotify = MapNotify;
    TypeMappingNotify = MappingNotify;
    TypeReparentNotify = ReparentNotify;
    TypeUnmapNotify = UnmapNotify;
    TypeVisibilityNotify = VisibilityNotify;
    
    // Colormap state notification
    TypeColormapNotify = ColormapNotify;
    
    // Client communication events
    TypeClientMessage = ClientMessage;
    TypePropertyNotify = PropertyNotify;
    TypeSelectionClear = SelectionClear;
    TypeSelectionNotify = SelectionNotify;
    TypeSelectionRequest = SelectionRequest;
}