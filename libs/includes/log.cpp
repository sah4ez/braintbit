#include <cstdarg>
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>

namespace EConsole
{

//// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    const std::string CurrentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
        // for more information about date/time format
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

        return buf;
    }
	//Print Now Time
    inline bool PrintNowTime()
    {
        try
        {
            std::cout << CurrentDateTime();
            return true;
        }
        catch (...)
        {
            return false;
        }

    }
	//Print Console Text
	bool PrintScreen(const char* fmt...)
	{
		try
		{
            PrintNowTime();
            std::cout << "[PS] ";
            std::cout << fmt;
            std::cout << std::endl;
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	bool PrintLn()
	{
		std::cout << std::endl;
		return true;
	}

	bool PrintScreenLine(const char* fmt...)
	{
		try
		{
            PrintNowTime();
            std::cout << "[PSL] ";
            std::cout << fmt;
            std::cout << std::endl;
			return true;
		}
		catch (...)
		{
			return false;
		}
	}
	bool PrintError(const char* fmt...)
	{
		try
		{
            PrintNowTime();
            std::cout << "[ERR] ";
            std::cout << fmt;
            std::cout << std::endl;
			return true;
		}
		catch (...)
		{
			return false;
		}
	}
    bool PrintLog(const char* fmt...)
    {
        try
        {
            PrintNowTime();
            std::cout << "[DEBUG] ";
            std::cout << fmt;
            std::cout << std::endl;
            return true;
        }
        catch (...)
        {
            return false;
        }

    }
}

