#include "main_scanner.h"
#include <unistd.h>

// =============
// || SCANNER ||
// =============

Sensor* SampleScannerFunction()
{
	/*

		FOR SEARCHING DEVICES WE NEED:
		1. CREATE SCANNER
		2. START SCANNER
		3. STOP SCANNER AFTER A TIME

	*/

	//Create list of sensor familyes, which we want to find. In our
	//example we choose 'SensorLEBrainBit & SensorLEBrainBit'.
	SensorFamily filters[] = { SensorFamily::SensorLEBrainBit, SensorFamily::SensorLEBrainBit };

	//Create object of custom scanner for getting SensorScanner
	//If you want to know, how to work with commands of library
	//you can look in folder 'scanner'.
	SampleScanner scanner(filters, sizeof(filters));


	//Start searching devices
	scanner.StartScanner();

	EConsole::PrintLog("start scanner");
	//Wait 8 seconds to find devices
	sleep(8);
	EConsole::PrintLog("stop listen and run");

	//Stop searching devices
	scanner.StopScanner();

	//Get list of found devices
	std::vector<SensorInfo> listDevices = scanner.GetDevices();

	//Check found device scanner or not. If no devices, return null value
	if (listDevices.size() == 0)
		return nullptr;

	//Print information of all found devices
	for (int i = 0; i < listDevices.size(); i++)
	{
		EConsole::PrintLog("[SENSOR] [NAME] : ");
		EConsole::PrintLog(listDevices[i].Name);
		EConsole::PrintLog(" [SERIAL NUMBERS] :");
		EConsole::PrintLog(listDevices[i].SerialNumber);
		EConsole::PrintLog(" [ADDRESS] :");
		EConsole::PrintLog(listDevices[i].Address);
	}

	//Create SensorInfo of first found device to create object of Sensor
	SensorInfo device = listDevices[0];

	//Create object Sensor with function 'CreateSensor' and return pointer of this object
	Sensor* sensor = scanner.CreateSensor(device);
	
	//Return pointer of object Sensor
	return sensor;
}

