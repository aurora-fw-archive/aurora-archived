// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/GUIApplication.h>
#include <Aurora/GUIWindow.h>
using namespace std;

arslot_t slot_MyApp_on_open()
{
	GUIWindow *FirstWindow = new GUIWindow("First Window", 800, 600, GUIWindow::NonePosition, GUIWindow::ToplevelWindow);
	FirstWindow->start();
}

int main(int argc, char * argv[])
{
	GUIApplication *MyApp = new GUIApplication("org.aurora.example", GUIApplication::NoneFlag, slot_MyApp_on_open, argc, argv);
	return MyApp->AppStatus;
}
