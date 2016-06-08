// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <X11/Xlib.h>
#include <Aurora/GUIEvent.h>

unsigned long GUIEvent::EventNone = NoEventMask; // No events wanted
unsigned long GUIEvent::EventKeyPress = KeyPressMask; // Keyboard down events wanted
unsigned long GUIEvent::EventKeyRelease = KeyReleaseMask; // Keyboard up events wanted
unsigned long GUIEvent::EventButtonPress = ButtonPressMask; // Pointer button down events wanted
unsigned long GUIEvent::EventButtonRelease = ButtonReleaseMask; // Pointer button up events wanted
unsigned long GUIEvent::EventEnterWindow = EnterWindowMask; // Pointer window entry events wanted
unsigned long GUIEvent::EventLeaveWindow = LeaveWindowMask; // Pointer window leave events wanted
unsigned long GUIEvent::EventPointerMotion = PointerMotionMask; // Pointer motion events wanted
unsigned long GUIEvent::EventPointerMotionHint = PointerMotionHintMask; // Pointer motion hints wanted
unsigned long GUIEvent::EventButton1Motion = Button1MotionMask; // Pointer motion while button 1 down
unsigned long GUIEvent::EventButton2Motion = Button2MotionMask; // Pointer motion while button 2 down
unsigned long GUIEvent::EventButton3Motion = Button3MotionMask; // Pointer motion while button 3 down
unsigned long GUIEvent::EventButton4Motion = Button4MotionMask; // Pointer motion while button 4 down
unsigned long GUIEvent::EventButton5Motion = Button5MotionMask; // Pointer motion while button 5 down
unsigned long GUIEvent::EventButtonMotion = ButtonMotionMask; // Pointer motion while any button down
unsigned long GUIEvent::EventKeymapState = KeymapStateMask; // Keyboard state wanted at window entry and focus in
unsigned long GUIEvent::EventExposure = ExposureMask; // Any exposure wanted
unsigned long GUIEvent::EventVisibilityChange = VisibilityChangeMask; // Any change in visibility wanted
unsigned long GUIEvent::EventStructureNotify = StructureNotifyMask; // Any change in window structure wanted
unsigned long GUIEvent::EventResizeRedirect = ResizeRedirectMask; // Redirect resize of this window
unsigned long GUIEvent::EventSubstructureNotify = SubstructureNotifyMask; // Substructure notification wanted
unsigned long GUIEvent::EventSubstructureRedirect = SubstructureRedirectMask; // Redirect structure requests on children
unsigned long GUIEvent::EventFocusChange = FocusChangeMask; // Any change in input focus wanted
unsigned long GUIEvent::EventPropertyChange = PropertyChangeMask; // Any change in property wanted
unsigned long GUIEvent::EventColormapChange = ColormapChangeMask; // Any change in colormap wanted
unsigned long GUIEvent::EventOwnerGrabButton = OwnerGrabButtonMask; // Automatic grabs should activate with owner_events set to True

// Keyboard events
int GUIEvent::TypeKeyPress = KeyPress;
int GUIEvent::TypeKeyRelease = KeyRelease;

// Pointer events
int GUIEvent::TypeButtonPress = ButtonPress;
int GUIEvent::TypeButtonRelease = ButtonRelease;
int GUIEvent::TypeMotionNotify = MotionNotify;

// Window crossing events
int GUIEvent::TypeEnterNotify = EnterNotify;
int GUIEvent::TypeLeaveNotify = LeaveNotify;

// Input focus events
int GUIEvent::TypeFocusIn = FocusIn;
int GUIEvent::TypeFocusOut = FocusOut;

// Keymap state notification events
int GUIEvent::TypeKeymapNotify = KeymapNotify;

// Exposure events
int GUIEvent::TypeExpose = Expose;
int GUIEvent::TypeGraphicsExpose = GraphicsExpose;
int GUIEvent::TypeNoExpose = NoExpose;

// Structure control events
int GUIEvent::TypeCirculateRequest = CirculateRequest;
int GUIEvent::TypeConfigureRequest = ConfigureRequest;
int GUIEvent::TypeMapRequest = MapRequest;
int GUIEvent::TypeResizeRequest = ResizeRequest;

// Window state notification
int GUIEvent::TypeCirculateNotify = CirculateNotify;
int GUIEvent::TypeConfigureNotify = ConfigureNotify;
int GUIEvent::TypeCreateNotify = CreateNotify;
int GUIEvent::TypeDestroyNotify = DestroyNotify;
int GUIEvent::TypeGravityNotify = GravityNotify;
int GUIEvent::TypeMapNotify = MapNotify;
int GUIEvent::TypeMappingNotify = MappingNotify;
int GUIEvent::TypeReparentNotify = ReparentNotify;
int GUIEvent::TypeUnmapNotify = UnmapNotify;
int GUIEvent::TypeVisibilityNotify = VisibilityNotify;

// Colormap state notification
int GUIEvent::TypeColormapNotify = ColormapNotify;

// Client communication events
int GUIEvent::TypeClientMessage = ClientMessage;
int GUIEvent::TypePropertyNotify = PropertyNotify;
int GUIEvent::TypeSelectionClear = SelectionClear;
int GUIEvent::TypeSelectionNotify = SelectionNotify;
int GUIEvent::TypeSelectionRequest = SelectionRequest;