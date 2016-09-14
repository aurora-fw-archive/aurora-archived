// "Examples/src/test_crypto.cpp" -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

/* @brief: Cryptography Module Test */

#include <Aurora/Aurora.h>
using namespace Aurora;

Application *MyApp;

ArSlot_t slot_MyApp_on_open()
{
	/*
	** @brief		AES Algorithm test
	** @description	Key 32 bytes
	** @description Block 16 bytes
	** @description	Keysize 128
	*/
	unsigned char k[32] = {0x1a, 0xaa};
	unsigned char c[16] = {0xa1, 0x11};
	Shell::Output << c << Shell::EndLine;
	Shell::Output << AES::encrypt(k, 128, c) << Shell::EndLine;
	Shell::Output << AES::decrypt(k, 128, AES::encrypt(k, 128, c)) << Shell::EndLine;
	Application::ExitSuccess();
}

int main(int argc, char * argv[])
{ 
	MyApp = new Application(slot_MyApp_on_open, argc, argv);
	return 0;
}