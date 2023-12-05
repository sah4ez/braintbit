#include <iostream>
#include <string>
#include <ctime>

namespace EConsole
{

	bool PrintScreen(const char* fmt...);
    const std::string CurrentDateTime() ;
    inline bool PrintNowTime();
    bool PrintLog(const char* fmt...);
    bool PrintScreenLine(const char* fmt...);
    bool PrintLn();
    bool PrintError(const char* fmt...);
}
