// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/CLI/Log.h>
#include <Aurora/Core/Debug.h>

namespace Aurora { namespace Debug
	{
		bool Status = false;
		bool isVerbose = false;
		int LastID;
		void enableDebug(bool silent)
		{
			if(Status)
			{
				if(!silent)
					Shell::Log(Shell::Debug, "debug is already enabled");
			}
			else
			{
				Status = true;
				if(!silent)
				{
					Shell::Log(Shell::Debug, "┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─");
					Shell::Log(Shell::Debug, "├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐");
					Shell::Log(Shell::Debug, "┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴");
					Shell::Log(Shell::Debug, "debug is enabled");
				}
			}
		}
		void disableDebug(bool silent)
		{
			if(!Status)
			{
				if(!silent) Shell::Log(Shell::Debug, "debug is already disabled");
			}
			else
			{
				Status = false;
				if(!silent) Shell::Log(Shell::Debug, "debug is disabled");
			}
		}
		bool getDebugStatus()
		{
			return Status;
		}
	}
}
