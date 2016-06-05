#ifndef _AURORA_SHELLLOG
#define _AURORA_SHELLLOG

#include <iostream>

namespace AuroraShell
{
    struct Log
    {
    public:
        static void Error (std::string body, bool newline = true);
        static void Warning (std::string body, bool newline = true);
        static void Notice (std::string body, bool newline = true);
        static void Information (std::string body, bool newline = true);
    };
}

#endif // _AURORA_SHELLLOG