#include <iostream>
// // #include <nlohmann/json.hpp>
#include <sdk_api.h>
#include "log.h"
#include "main_scanner.h"
#include "main_brainbit.h"
#include "main_filters.h"
#include <typeinfo>

// using json = nlohmann::json;

void BrainBitFunction()
{
	//Create Sensor to connect to device (LEBrainBit)
	Sensor* brainbit = SampleScannerFunction();
	EConsole::PrintLog("create instance");

	//If object is null, show information of not found device and stop code
	if (brainbit == nullptr)
	{
		EConsole::PrintLog("Can't find device!");
		return;
	}

	EConsole::PrintLog("run function");
	//Compile code to connect device & control
	SampleBrainBitFunction(brainbit);
}

void BrainBitFiltersFunction()
{
	//Create Sensor to connect to device (LEBrainBit)
	Sensor* brainbit = SampleScannerFunction();

	//If object is null, show information of not found device and stop code
	if (brainbit == nullptr)
	{
		EConsole::PrintLog("Can't find device!");
		return;
	}

	EConsole::PrintLog("start scanner");
	//Compile code to using lib 'filters'
	SampleBrainBitFilters(brainbit);
}

int main()
{
    // json object = { { "msg", "start" }, { "p", 1 } };
    // std::cout << object << '\n';
    std::cout << "hello1" << '\n';
    BrainBitFunction();
	// BrainBitFiltersFunction();
    // object = { { "msg", "end" }, { "p", 2 } };
    std::cout << "hello2" << '\n';
    return 0;
}
