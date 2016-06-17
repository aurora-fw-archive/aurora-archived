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
	if(!getDebugStatus())
	{
		Shell::Log(Shell::Notice, "debug is disable", Shell::EndLine);
	}
	if(Debug)
	{
		Shell::Log(Shell::Notice, "test the log", Shell::EndLine);
		Shell::Log(Shell::Warning, "test the log", Shell::EndLine);
		Shell::Log(Shell::Error, "test the log", Shell::EndLine);
		Shell::Log(Shell::Notice,"test the log", Shell::EndLine);
		Shell::Log(Shell::Debug, "test the log", Shell::EndLine);
	}
	Shell::Log(Shell::Information, "Getting total virtual memory:\t");
  Shell::Output(InfoRAM::getTotalVirtualMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting used virtual memory:\t");
  Shell::Output(InfoRAM::getUsedVirtualMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting free virtual memory:\t");
  Shell::Output(InfoRAM::getFreeVirtualMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting total physical memory:\t");
  Shell::Output(InfoRAM::getTotalPhysicalMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting used physical memory:\t");
  Shell::Output(InfoRAM::getUsedPhysicalMemory(), Shell::EndLine);
	Shell::Log(Shell::Information, "Getting free physical memory:\t");
  Shell::Output(InfoRAM::getFreePhysicalMemory(), Shell::EndLine);
  Application::ExitSuccess();
}

int main(int argc, char * argv[])
{
    MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
    return 0;
}
