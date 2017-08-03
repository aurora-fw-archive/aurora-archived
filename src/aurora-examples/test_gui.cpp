// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: src/Examples/src/test_gui.cpp
// Contains:

#include <Aurora/Aurora.h>
using namespace Aurora;


GUI::Application *MyGUIApp;
GUI::Window *FirstWindow;
GUI::Label *HelloLabel;
GUI::Button *TestButton;

ArSlot_t slot_MyWindow_on_open()
{
	HelloLabel->setText("Hello, World!");
	HelloLabel->setSelectable(true);
	HelloLabel->setWrap(true);
	HelloLabel->setWrapMode(GUI::WrapMode::Word);
	HelloLabel->setAlignment(GUI::AlignMode::Custom);
	HelloLabel->setAlignment(0.7, 0.8);
	GUI::AlignMode alignLabel = HelloLabel->getAlignment();
	Shell::Log(Shell::Information,"X: ", HelloLabel->getXAlignment());
	Shell::Log(Shell::Information,"Y: ", HelloLabel->getYAlignment());
}

ArSlot_t slot_MyGUIApp_on_open()
{
	FirstWindow = new GUI::Window("First Window", 800, 600, GUI::Window::NonePosition, GUI::Window::ToplevelWindow);
	TestButton = new GUI::Button(FirstWindow, "TestButton");
	HelloLabel = new GUI::Label(FirstWindow, "Hello World!");
	FirstWindow->start(slot_MyWindow_on_open);
}

int main(int argc, char * argv[])
{
	MyGUIApp = new GUI::Application("org.aurora.example", GUI::Application::NoneFlag, slot_MyGUIApp_on_open, argc, argv);
	return MyGUIApp->AppStatus;
}
