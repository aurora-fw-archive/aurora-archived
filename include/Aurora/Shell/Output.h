
#ifndef INCLUDE_H_AURORA_SHELL_OUTPUT
#define INCLUDE_H_AURORA_SHELL_OUTPUT

#pragma once

#include <ostream>

namespace Aurora { namespace Shell
    {
        extern std::ostream Output;
        extern std::wostream wOutput;

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits>&
        EndLine(std::basic_ostream<_CharT, _Traits>& __os)
        { return flush(__os.put(__os.widen('\n'))); }

        template<typename _CharT, typename _Traits>
        inline std::basic_ostream<_CharT, _Traits>&
        Flush(std::basic_ostream<_CharT, _Traits>& __os)
        { return __os.flush(); }
    }
}

#endif // INCLUDE_H_AURORA_SHELL_OUTPUT