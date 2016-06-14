// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Shell/Log.h>
#include <Aurora/Core/Debug.h>
#include <Aurora/Core/Macros.h>

namespace Aurora
{
    void enableDebug(bool silent)
    {
        if(Debug)
        {
            if(!silent) ShellLog::Debug("debug is already enabled");
        }
        else
        {
            Debug = true;
            if(!silent) 
            {
                ShellLog::Debug("┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─");
                ShellLog::Debug("├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐");
                ShellLog::Debug("┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴");
                ShellLog::Debug("debug is enabled");
            }
        }
    }
    void disableDebug(bool silent)
    {
        if(!Debug)
        {
            if(!silent) ShellLog::Debug("debug is already disabled");
        }
        else
        {
            Debug = false;
            if(!silent) ShellLog::Debug("debug is disabled");   
        }
    }
    bool getDebugStatus()
    {
        return Debug;
    }
}