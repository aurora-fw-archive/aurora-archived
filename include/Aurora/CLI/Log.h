// <Aurora/Shell/Log.h> -*- C++ -*-
// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

// This file is part of the Aurora Framework. This framework is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License, v3.

#ifndef INCLUDE_H_AURORA_SHELL_LOG
#define INCLUDE_H_AURORA_SHELL_LOG

#include <Aurora/TLib/Target/PragmaOnce.h>
#if defined(AURORA_TARGET_PRAGMA_ONCE_SUPPORT) && AURORA_TARGET_PRAGMA_ONCE_SUPPORT
    #pragma once
#endif

#ifndef AURORA_FW
#define AURORA_FW 1
#endif // AURORA_FW

#include <Aurora/TLib/Target/Environment.h>
#include <Aurora/CLI/Output.h>
#include <Aurora/Core/Debug.h>

namespace Aurora { namespace Shell
	{
		enum MessageStatus
		{
			Error,
			Warning,
			Notice,
			Information,
			Debug
		};

		void __Log(auto t)
		{
			Output << t;
		}

		void __Log(auto t, auto... args)
		{
			Output << t;
			__Log(args...);
		}

		void Log (MessageStatus status, auto... args)
		{
			// TODO: Windows ANSI integration
			//       Needs to be tested on Windows and Apple platforms
			if(status == Error)
			{
				#ifdef AURORA_TARGET_ENVIRONMENT_UNIX
				Output << "\e[0m\e[1m[\e[1;31mERROR\e[0;1m] \e[0m";
				#else
				Output << "[ERROR] ";
				#endif
			}
			else if (status == Warning)
			{
				#ifdef AURORA_TARGET_ENVIRONMENT_UNIX
				Output << "\e[0m\e[1m[\e[1;33mWARNING\e[0;1m] \e[0m";
				#else
				Output << "[WARNING] ";
				#endif
			}
			else if (status == Notice)
			{
				#ifdef AURORA_TARGET_ENVIRONMENT_UNIX
				Output << "\e[0m\e[1m[\e[1;36mNOTICE\e[0;1m] \e[0m";
				#else
				Output << "[NOTICE] ";
				#endif
			}
			else if (status == Information)
			{
				#ifdef AURORA_TARGET_ENVIRONMENT_UNIX
				Output << "\e[0m\e[1m[\e[1;32mINFORMATION\e[0;1m] \e[0m";
				#else
				Output << "[INFORMATION] ";
				#endif
			}
			else if (status == Aurora::Shell::Debug)
			{
				if(Aurora::Debug::Status)
				{
					#if AURORA_DEBUG_LOG

					#else
						if(Debug::isVerbose == false)
						#ifdef AURORA_TARGET_ENVIRONMENT_UNIX
							Output << "\e[0m\e[1m[\e[1;36mDEBUG\e[0;1m] \e[0m";
						#else
							Output << "[DEBUG] ";
						#endif
						__Log(args...);
						Output << EndLine;
					#endif
					return;
				}
				else return;
			}
			__Log(args...);
			Output << EndLine;
		}
	}
}

#endif // INCLUDE_H_AURORA_SHELL_LOG
