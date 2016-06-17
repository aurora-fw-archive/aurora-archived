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

arslot_t slot_MyApp_on_open()
{
	if(!Debug::getDebugStatus())
	{
		Shell::Log(Shell::Notice, "debug is disable", Shell::EndLine);
	}
	if(Debug::getDebugStatus())
	{
		Shell::Log(Shell::Notice, "test the log", Shell::EndLine);
		Shell::Log(Shell::Warning, "test the log", Shell::EndLine);
		Shell::Log(Shell::Error, "test the log", Shell::EndLine);
		Shell::Log(Shell::Notice,"test the log", Shell::EndLine);
		Shell::Log(Shell::Debug, "test the log", Shell::EndLine);
	}
	#ifdef __AURORA_FW
		Shell::Log(Shell::Notice, "Aurora Framework Macro detected!", Shell::EndLine);
	#endif

	Shell::Log(Shell::Information, "Getting total virtual memory:\t\t");
  Shell::Output(InfoRAM::getTotalVirtualMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting used virtual memory:\t\t");
  Shell::Output(InfoRAM::getUsedVirtualMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting free virtual memory:\t\t");
  Shell::Output(InfoRAM::getFreeVirtualMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting total physical memory:\t\t");
  Shell::Output(InfoRAM::getTotalPhysicalMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting used physical memory:\t\t");
  Shell::Output(InfoRAM::getUsedPhysicalMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting free physical memory:\t\t");
  Shell::Output(InfoRAM::getFreePhysicalMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting Operation System Name:\t\t");
	Shell::Output(InfoOS::getName(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting Operation System Architecture:\t");
	Shell::Output(InfoOS::getArchitecture(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting Operation System Manufacturer:\t");
	Shell::Output(InfoOS::getManufacturer(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting Operation System Version:\t\t");
	Shell::Output(InfoOS::getVersion(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting User Computer Name:\t\t");
	Shell::Output(InfoOS::getUserComputerName(), Shell::EndLine);
  Application::ExitSuccess();
}

int main(int argc, char * argv[])
{
    MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
    return 0;
}
