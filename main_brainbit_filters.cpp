#include "main_brainbit_em_st_artifacts.h"
#include "filtersLib.h"
#include "brainbit.h"
#include <unistd.h>

void SampleBrainBitFilters(Sensor* sensor_brainbit)
{
	EConsole::PrintLog("[LOG] create");
	//Create custom object of Filters
	FiltersLibSample* filtersLib = new FiltersLibSample();
	EConsole::PrintLog("[LOG] filter");

	//If lib is null, stop code
	if (filtersLib == nullptr)
		return;

	EConsole::PrintLog("[LOG] start filter");
	//Create custom object of BrainBit.
	//If you want to know, how to work with device ('LEBrainBit')
	//you can look in folder 'brainbit'.
	SampleBrainBit* brainbit = new SampleBrainBit(sensor_brainbit);

	//Check if object of BrainBit is null or not
	if (brainbit == nullptr)
		return;

	//Add callback to get signal data and send to filter lib for convert raw data
	brainbit->AddSignalCallbackBrainBit_Filters(filtersLib);
	EConsole::PrintLog("[LOG] add filter");

	//To execuate command we use function 'execCommand'.
	//Before use this command you need to be sure,
	//that this device supports this command

	//Create SensorCommand to execuate it
	SensorCommand command_start_signal = CommandStartSignal;

	//Check if support this device command 'CommandStartSignal'
	bool isSupport = brainbit->isSupportedCommand(command_start_signal);

	//It is recommended to be sure of availabilities device. You can check and
	//execuate commands like it:
	//
	//if(brainbit->isSupportedCommand(command_start_signal))
	//{
	//	brainbit->execCommand(command_start_signal)
	//}

	//Check if our command is supported for device
	if (isSupport)
	{
		EConsole::PrintLog("[LOG] [This command is supported by device!");

		//If this command is supported by device, you can execuate it

		brainbit->execCommand(command_start_signal);
	}
	else
	{
		EConsole::PrintLog("[WARNING] [This command is not supported by device!");
	}

	EConsole::PrintLog("start sleep");
	//Wait 10 seconds to get signal data
	sleep(10);

	//Create SensorCommand to execuate it
	SensorCommand command_stop_signal = CommandStopSignal;

	//Check if support this device command 'CommandStopSignal'
	isSupport = brainbit->isSupportedCommand(command_stop_signal);

	//Check if our command is supported for device
	if (isSupport)
	{
		EConsole::PrintLog("[LOG] [This command is supported by device!");

		//If this command is supported by device, you can execuate it

		brainbit->execCommand(command_stop_signal);
	}
	else
	{
		EConsole::PrintLog("[WARNING] [This command is not supported by device!");
	}

	//Remove signal callback
	brainbit->RemoveSignalCallbackBrainBit_Filters();

	EConsole::PrintLog("stop sleep");
	//Wait 2 seconds
	sleep(2);

	//Clear memory of object brainbit
	delete brainbit;

	//Clear memory of object class
	delete filtersLib;
}
