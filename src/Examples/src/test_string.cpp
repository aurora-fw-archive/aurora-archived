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

ArInt_t main(ArInt_t argc, ArChar_t * argv[])
{
	Ar::String inputstr;
	Shell::Input >> inputstr;
	Shell::Output << inputstr;
	/*
	// new String by Copy
	Ar::String World = "World!";
	Ar::String CpWorld(World);
	Shell::Output << CpWorld << Shell::EndLine;*/

	/*Ar::String hello_world = "Hello" + ", World!";
	Shell::Output << hello_world << Shell::EndLine;*/
	// Input
	/*Ar::String read_str;
	Shell::Input >> read_str;
	Shell::Output << "Reading: "<< read_str;*/
}