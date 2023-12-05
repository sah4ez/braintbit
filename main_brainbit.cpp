#include "main_brainbit.h"
#include "mathLib.h"
#include <unistd.h>

// ==============
// || BRAINBIT ||
// ==============

void SampleBrainBitFunction(Sensor* sensor_brainbit)
{
	//Create custom object of BrainBit.
	//If you want to know, how to work with device ('LEBrainBit & LEBrainBitBlack')
	//you can look in folder 'brainbit'.
	SampleBrainBit* brainbit = new SampleBrainBit(sensor_brainbit);

	//In this examples you can see some functions to
	//control device 'LEBrainBit & LEBrainBitBlack'.

	//Read name of device
	std::string name = brainbit->readName();

	//Disconnect from device
	// brainbit->disconnect();

	//Connect to device
	brainbit->connect();
    int32_t power_t = brainbit->readBatteryPower();
    std::cout << "power: " << power_t << std::endl;

    int32_t cnt = brainbit->getChannelsCount();
    std::cout << "channel_count: " << cnt << std::endl;

    int8_t freq = brainbit->readSamplingFrequency();
    std::cout << "sampling freq: " << freq << std::endl;

    int32_t gain = brainbit->readGain();
    std::cout << "gain: " << gain << std::endl;

    MathLibSample* mathLib = new MathLibSample();
    //
    //      //If lib is null, stop code
    if (mathLib == nullptr)
            return;

    brainbit->AddSignalCallbackBrainBit_EmStArtifacts(mathLib);
    //

    SensorParameter parameter =  SensorParameter::ParameterSamplingFrequency;
	bool isSupportParam = brainbit->isSupportedParameter(parameter);
    if (isSupportParam) {
		EConsole::PrintLog("[LOG] supported parameter");
    }


	SensorCommand command = SensorCommand::CommandStartSignal;

	bool isSupport = brainbit->isSupportedCommand(command);

	if (isSupport)
	{
		EConsole::PrintLog("[LOG] [This command is supported by device!");
  
  		//If this command is supported by device, you can execuate it
  
		brainbit->execCommand(command);
	}
	else
	{
		EConsole::PrintLog("[WARNING] [This command is not supported by device!");
	}


    EConsole::PrintLog("exec command and wait callback");
    sleep(100);

	//If you don't use object of custom class, you need to
	// delete to clear memory.
    brainbit->RemoveSignalCallbackBrainBit_EmStArtifacts();
	delete brainbit;
}
