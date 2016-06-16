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
            if(!silent) Shell::Log(Shell::Debug, "debug is already enabled", Shell::EndLine);
        }
        else
        {
            Debug = true;
            if(!silent) 
            {
                Shell::Log(Shell::Debug, "┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─", Shell::EndLine);
                Shell::Log(Shell::Debug, "├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐", Shell::EndLine);
                Shell::Log(Shell::Debug, "┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴", Shell::EndLine);
                Shell::Log(Shell::Debug, "debug is enabled", Shell::EndLine);
            }
        }
    }
    void disableDebug(bool silent)
    {
        if(!Debug)
        {
            if(!silent) Shell::Log(Shell::Debug, "debug is already disabled", Shell::EndLine);
        }
        else
        {
            Debug = false;
            if(!silent) Shell::Log(Shell::Debug, "debug is disabled", Shell::EndLine);
        }
    }
    bool getDebugStatus()
    {
        return Debug;
    }
}