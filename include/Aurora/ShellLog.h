#ifndef _AURORA_SHELLLOG
#define _AURORA_SHELLLOG

namespace ShellLog 
{
    void Error (std::string body, bool newline = true);
    void Warning (std::string body, bool newline = true);
    void Notice (std::string body, bool newline = true);
    void Information (std::string body, bool newline = true);
}

#endif // _AURORA_SHELLLOG