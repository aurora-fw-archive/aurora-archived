// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// File: src/Examples/src/test_string.cpp
// Contains: Tests and Examples for Aurora Framework (String Example)

#include <Aurora/Aurora.h>
#include <iostream>

using namespace Aurora;
Application *MyApp;

ArSlot_t slot_MyApp_on_open()
{
	Shell::Output << sizeof(char) << Shell::EndLine;

	/*
	** @brief Creating a normal string - Procidual operations
	*/
	Shell::Log(Shell::Debug, "creating a string and output it...");
	Ar::String TestString("Test!");
	Shell::Output << TestString << Shell::EndLine;
	if(TestString.length() == 5)
		Shell::setColor(Shell::Color::Green, Shell::ColorType::Foreground);
	else
		Shell::setColor(Shell::Color::Red, Shell::ColorType::Foreground);
	Shell::Output << TestString.length() << Shell::EndLine;
	Shell::resetColor();

	Shell::Log(Shell::Debug, "done.");
	Shell::Log(Shell::Debug, "creating a wide string and output it...");
	Ar::wString wTestString(L"Test!");
	Shell::wOutput << wTestString << Shell::EndLine;
	Shell::wOutput << wTestString.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");

	/*
	** @brief String by Copy - Procidual operations
	*/
	Shell::Log(Shell::Debug, "creating a string by copy and output it...");
	Ar::String World = " World!";
	Ar::String CpWorld(World);
	Shell::Output << CpWorld << Shell::EndLine;
	Shell::Output << CpWorld.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");
	Shell::Log(Shell::Debug, "creating a wide string by copy and output it...");
	Ar::wString wWorld = L" World!";
	Ar::wString wCpWorld(wWorld);
	Shell::wOutput << wCpWorld << Shell::EndLine;
	Shell::wOutput << wCpWorld.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");

	/*
	** @brief Concatenation procidual operations
	*/
	Shell::Log(Shell::Debug, "creating two strings, try to contatenate them with operator+ and output the result...");
	Ar::String Hello = "Hello,";
	Shell::Log(Shell::Debug, "concatenation process...");
	Ar::String HelloWorld = Hello + World;
	Shell::Output << HelloWorld << Shell::EndLine;
	Shell::Output << HelloWorld.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");
	Shell::Log(Shell::Debug, "creating two wide strings, try to contatenate them with operator+ and output the result...");
	Ar::wString wHello = L"Hello,";
	Shell::Log(Shell::Debug, "concatenation process...");
	Ar::wString wHelloWorld = wHello + wWorld;
	Shell::wOutput << wHelloWorld << Shell::EndLine;
	Shell::wOutput << wHelloWorld.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");

	/*
	** @brief procidual operations for += operator (using char ptr)
	*/
	Shell::Log(Shell::Debug, "creating a string and try to use +=operator with a char pointer and output the result...");
	Ar::String SomeString = "Hello";
	SomeString += ", World";
	Shell::Output << SomeString << Shell::EndLine;
	Shell::Output << SomeString.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");

	/*
	** @brief Procidual operations for += operator (using two strings)
	*/
	Shell::Log(Shell::Debug, "creating a string and try to use +=operator with another string and output the result...");
	Ar::String SomeString2 = "Message: ";
	SomeString2 += SomeString;
	Shell::Output << SomeString2 << Shell::EndLine;
	Shell::Output << SomeString2.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");

	Shell::Log(Shell::Debug, "creating two strings and try to use conditional ==operator with another string and output the result...");
	Ar::String Check1Eq = "Hello";
	Ar::String Check2Eq = Check1Eq;
	bool checkEq = Check1Eq == Check2Eq;
	Shell::Log(Shell::Information, "the result need to be true");
	Shell::Output << checkEq << Shell::EndLine;
	checkEq = Check1Eq == "Hello";
	Shell::Log(Shell::Information, "the result need to be true");
	Shell::Output << checkEq << Shell::EndLine;
	Shell::Log(Shell::Debug, "try to use conditional !=operator and output the result...");
	checkEq = Check1Eq != Check2Eq;
	Shell::Log(Shell::Information, "the result need to be false");
	Shell::Output << checkEq << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");

	Shell::Log(Shell::Debug, "try to find a string inside an another string");
	Ar::String findStr = "World Hello!";
	Ar::String tmp_str = "Hello";
	Shell::Log(Shell::Information, "the result need to be 6");
	Shell::Output << findStr.find(tmp_str, 0) << Shell::EndLine;

	Shell::Log(Shell::Debug, "try to find an array of chars inside a string");
	Ar::String findStr2 = "World Hello!";
	Shell::Log(Shell::Information, "the result need to be 6");
	Shell::Output << findStr2.find("Hello", 0) << Shell::EndLine;

	Shell::Log(Shell::Debug, "try to find an array of chars inside a string with a specific counter");
	Ar::String findStr3 = "HHHH";
	Shell::Log(Shell::Information, "the result need to be 21");
	Shell::Output << findStr3.find("H", 0, 4) << Shell::EndLine;

	Shell::Log(Shell::Debug, "creating two strings and try to use conditional !=operator with another string and output the result...");
	Ar::String Check1NEq = "Hello";
	Ar::String Check2NEq = "World!";
	bool checkNEq =  Check1NEq != Check2NEq;
	Shell::Log(Shell::Information, "the result need to be true");
	Shell::Output << checkNEq << Shell::EndLine;
	checkNEq = Check1NEq != "World!";
	Shell::Log(Shell::Information, "the result need to be true");
	Shell::Output << checkNEq << Shell::EndLine;
	Shell::Log(Shell::Debug, "try to use conditional ==operator and output the result...");
	checkNEq =  Check1NEq == Check2NEq;
	Shell::Log(Shell::Information, "the result need to be false");
	Shell::Output << checkNEq << Shell::EndLine;

	Shell::Log(Shell::Debug, "testing operator>> and output the input...");
	Shell::Log(Shell::Information, "You need to input something in the shell...");
	Ar::String inputstr;
	Shell::Input >> inputstr;
	Shell::Log(Shell::Debug, "reading input...");
	Shell::Output << inputstr << Shell::EndLine;
	Shell::Output << inputstr.length() << Shell::EndLine;
	Shell::Log(Shell::Debug, "done.");
}

ArInt_t main(ArInt_t argc, ArChar_t * argv[])
{
	MyApp = new Application(slot_MyApp_on_open, argc, argv);
	delete MyApp;
	return 0;
}
