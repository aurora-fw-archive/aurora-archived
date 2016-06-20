// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Shell/Log.hpp>
#include <Aurora/Core/Debug.h>

namespace Aurora { namespace Debug
    {
        bool Status = false;
        int LastID;
        void enableDebug(bool silent)
        {
            if(Status)
            {
                if(!silent) Shell::Log(Shell::Debug, "debug is already enabled", Shell::EndLine);
            }
            else
            {
                Status = true;
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
            if(!Status)
            {
                if(!silent) Shell::Log(Shell::Debug, "debug is already disabled", Shell::EndLine);
            }
            else
            {
                Status = false;
                if(!silent) Shell::Log(Shell::Debug, "debug is disabled", Shell::EndLine);
            }
        }
        bool getDebugStatus()
        {
            return Status;
        }
    }
}
