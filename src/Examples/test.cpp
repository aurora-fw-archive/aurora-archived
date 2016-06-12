// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Aurora.h>

using namespace Aurora;
using namespace std;

Application *MyApp;
GUIApplication *MyGUIApp;
GUIWindow *FirstWindow;
GUILabel *HelloLabel;

arslot_t slot_MyWindow_on_open()
{
	// Application::ExitSuccess();
}

arslot_t slot_MyGUIApp_on_open()
{
	FirstWindow = new GUIWindow("First Window", 800, 600, GUIWindow::NonePosition, GUIWindow::ToplevelWindow);
	HelloLabel = new GUILabel(FirstWindow, "Hello World!");
	FirstWindow->start(slot_MyWindow_on_open);
}

arslot_t slot_MyApp_on_open()
{
	ShellLog::Information("Getting total virtual memory:\t", false);
	cout << InfoRAM::getTotalVirtualMemory() << endl;
	ShellLog::Information("Getting used virtual memory:\t", false);
	cout << InfoRAM::getUsedVirtualMemory() << endl;
	ShellLog::Information("Getting free virtual memory:\t", false);
	cout << InfoRAM::getFreeVirtualMemory() << endl;
	ShellLog::Information("Getting total physical memory:\t", false);
	cout << InfoRAM::getTotalPhysicalMemory() << endl;
	ShellLog::Information("Getting used physical memory:\t", false);
	cout << InfoRAM::getUsedPhysicalMemory() << endl;
	ShellLog::Information("Getting free physical memory:\t", false);
	cout << InfoRAM::getFreePhysicalMemory() << endl;
}

int main(int argc, char * argv[])
{
	MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
	MyGUIApp = new GUIApplication("org.aurora.example", GUIApplication::NoneFlag, slot_MyGUIApp_on_open, argc, argv);
	return MyGUIApp->AppStatus;
}
