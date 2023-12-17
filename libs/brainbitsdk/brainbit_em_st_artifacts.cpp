#include "brainbit.h"
#include <vector>
#include <iostream>
#include <fstream>

#include "common_api.h"

#include "log.h"

#include "mathLib.h"

void SignalCallback_EmStArtifacts(Sensor* sensor, BrainBitSignalData* data, int32_t size, void* userData)
{
    // EConsole::PrintLog("=== BRAIN BIT SIGNAL DATA ===");
    RawChannels* arr = new RawChannels[size];
    std::ofstream out_dt ("../dt.cpp", std::ios::out | std::ios::app);
    std::ofstream out_o1 ("../o1.cpp", std::ios::out | std::ios::app);
    std::ofstream out_o2 ("../o2.cpp", std::ios::out | std::ios::app);
    std::ofstream out_t3 ("../t3.cpp", std::ios::out | std::ios::app);
    std::ofstream out_t4 ("../t4.cpp", std::ios::out | std::ios::app);
    for (int i = 0; i < size; i++)
    {
            arr[i].left_bipolar = data[i].T3 - data[i].O1;
            arr[i].right_bipolar = data[i].T4 - data[i].O2;

            out_dt << "," <<EConsole::CurrentDateTime();
            out_dt << std::endl;

            out_o1 << "," <<data[i].O1;
            out_o1 << std::endl;

            out_o2 << "," << data[i].O2;
            out_o2 << std::endl;

            out_t3 << "," <<data[i].T3;
            out_t3 << std::endl;

            out_t4 << "," << data[i].T4;
            out_t4 << std::endl;
            // EConsole::PrintLog("Left bipolar: ", arr[i].left_bipolar);
            // EConsole::PrintLog("Right bipolar: ", arr[i].right_bipolar);
        }
    out_dt.close(); 
    out_o1.close(); 
    out_o2.close(); 
    out_t3.close(); 
    out_t4.close(); 
    // MathLibSample* mathLib = (MathLibSample*)userData;

    // mathLib->pushData(arr, size);
    // mathLib->processData();
    // mathLib->printResult();

    delete[] arr;
}



bool SampleBrainBit::AddSignalCallbackBrainBit_EmStArtifacts(MathLibSample* mathlib)
{
    try
    {
        //Check if our sensor is empty or not.
        if (_sensor == nullptr)
            throw std::invalid_argument("Null sensor!");

        OpStatus outStatus;

        bool result = addSignalDataCallbackBrainBit(_sensor, SignalCallback_EmStArtifacts, &_lSignalDataEmStArtifactsHandle, mathlib, &outStatus);

        if (!result)
        {
            throw std::invalid_argument(outStatus.ErrorMsg);
        }

        return true;
    }
    catch (std::exception error)
    {
        //Print Error Message on Console.
        EConsole::PrintScreen("[[ERROR : ", error.what(), " ]]");
        //Return false value means our algorythm is working incorrect.
        return false;
    }
    catch (...)
    {
        //Print Error Message on Console (unknown error).
        EConsole::PrintScreen("[[ERROR : Invalid error! ]]");
        //Return false value means our algorythm is working incorrect.
        return false;
    }
}

bool SampleBrainBit::RemoveSignalCallbackBrainBit_EmStArtifacts()
{
    try
    {
        //Check if our sensor is empty or not.
        if (_sensor == nullptr)
            throw std::invalid_argument("Null sensor!");

        if (_lSignalDataEmStArtifactsHandle == 0)
        {
            throw std::invalid_argument("Null Signal Data for EmStArtifacts handle!");
        }

        removeSignalDataCallbackBrainBit(_lSignalDataEmStArtifactsHandle);
        _lSignalDataEmStArtifactsHandle = 0;

        return true;
    }
    catch (std::exception error)
    {
        //Print Error Message on Console.
        EConsole::PrintScreen("[[ERROR : ", error.what(), " ]]");
        //Return false value means our algorythm is working incorrect.
        return false;
    }
    catch (...)
    {
        //Print Error Message on Console (unknown error).
        EConsole::PrintScreen("[[ERROR : Invalid error! ]]");
        //Return false value means our algorythm is working incorrect.
        return false;
    }
}
