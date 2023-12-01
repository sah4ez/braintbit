#pragma once

#include "sdk_api.h"
#include "log.h"

#include <vector>

/*
		#########################
		#						#
		#	 SAMPLES SCANNER	#
		#						#
		#########################


	Task: Class for management with SensorScanner 
	(searching devices and connection to one of them).

*/

class SampleScanner
{
public:
	//Create object SensorScanner for seaching devicesand get list of found ones.
	SampleScanner(SensorFamily* listFilters, int32_t countFilters);

	//Destructor of class
	~SampleScanner();

	//Begin searching devices.
	bool StartScanner();

	//Finish searching devices.
	bool StopScanner();

	//Get list of all found devices by scanning.
	std::vector<SensorInfo> GetDevices();

	bool AddSensorsCallbackScanner();
	bool RemoveSensorsCallbackScanner();

	//Create object of device for its controlling.
	Sensor* CreateSensor(SensorInfo device);

private:
	//Object Scanner (need for scanning devices).
	SensorScanner* _scanner = nullptr;

	//SensorListener is necessary for get target callback and remove it.
	SensorsListenerHandle _handle = nullptr;
};

