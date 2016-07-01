// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: src/Examples/src/test_shell.cpp
// Contains: Tests and Examples for Aurora Framework (Shell Example)

#include <Aurora/Aurora.h>
using namespace Aurora;

Application *MyApp;

ArSlot_t slot_MyApp_on_open()
{
	if(!Debug::getDebugStatus())
	{
		Shell::Log(Shell::Notice, "debug is disable");
	}
	if(Debug::getDebugStatus())
	{
		Shell::Log(Shell::Notice, "test the log");
		Shell::Log(Shell::Warning, "test the log");
		Shell::Log(Shell::Error, "test the log");
		Shell::Log(Shell::Notice,"test the log");
		Shell::Log(Shell::Debug, "test the log");
	}
	#ifdef __AURORA_FW
		Shell::Log(Shell::Notice, "Aurora Framework Macro detected!");
	#endif
	#ifdef __AURORA_LIB
		Shell::Log(Shell::Notice, "Aurora Library Macro detected!");
	#endif

	Shell::Log(Shell::Information, "Getting total virtual memory:\t\t", InfoRAM::getTotalVirtualMemory());
	Shell::Log(Shell::Information, "Getting used virtual memory:\t\t", InfoRAM::getUsedVirtualMemory());
	Shell::Log(Shell::Information, "Getting free virtual memory:\t\t", InfoRAM::getFreeVirtualMemory());
	Shell::Log(Shell::Information, "Getting total physical memory:\t\t", InfoRAM::getTotalPhysicalMemory());
	Shell::Log(Shell::Information, "Getting used physical memory:\t\t", InfoRAM::getUsedPhysicalMemory());
	Shell::Log(Shell::Information, "Getting free physical memory:\t\t", InfoRAM::getFreePhysicalMemory());
	Shell::Log(Shell::Information, "Getting Operation System Name:\t\t", InfoOS::getName());
	Shell::Log(Shell::Information, "Getting Operation System Architecture:\t", InfoOS::getArchitecture());
	Shell::Log(Shell::Information, "Getting Operation System Manufacturer:\t", InfoOS::getManufacturer());
	Shell::Log(Shell::Information, "Getting Operation System Version:\t\t", InfoOS::getVersion());
	Shell::Log(Shell::Information, "Getting User Computer Name:\t\t", InfoOS::getUserComputerName());

	//Input testing
	Shell::Output << "Insert something: ";
	int hello;
	Shell::Input >> hello;
	Shell::Output << hello << Shell::EndLine;
	Application::ExitSuccess();
}

int main(int argc, char * argv[])
{
	MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
	return 0;
}
