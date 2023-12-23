#pragma once

#include "sdk_api.h"
#include "log.h"

void SignalCallback(Sensor* sensor, BrainBitSignalData* data, int32_t size, void* userData)
{
	for (int i = 0; i < size; i++)
	{
        std::cout << EConsole::CurrentDateTime();
        // std::cout << std::endl;
        std::cout << "," <<data[i].PackNum;
        std::cout << "," <<data[i].Marker;

        std::cout << "," <<data[i].O1;
        // std::cout << std::endl;

        std::cout << "," << data[i].O2;
        // std::cout << std::endl;

        std::cout << "," <<data[i].T3;
        // std::cout << std::endl;

        std::cout << "," << data[i].T4;
        std::cout << std::endl;
	}
}
