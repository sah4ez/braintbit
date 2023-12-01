#include "brainbit.h"

//#include "signalCallback_spectrum.h"
//
//bool SampleBrainBit::AddSignalCallbackBrainBit_Spectrum(SpectrumLibSample* mathlib)
//{
//	try
//	{
//		//Check if our sensor is empty or not.
//		if (_sensor == nullptr)
//			throw std::invalid_argument("Null sensor!");
//
//		OpStatus outStatus;
//
//		bool result = addSignalDataCallbackBrainBit(_sensor, SignalCallback_Spectrum, &_lSignalDataSpectrumHandle, mathlib, &outStatus);
//
//		if (!result)
//		{
//			throw std::invalid_argument(outStatus.ErrorMsg);
//		}
//
//		return true;
//	}
//	catch (std::exception error)
//	{
//		//Print Error Message on Console.
//		EConsole::PrintScreen("[[ERROR : ", error.what(), " ]]");
//		//Return false value means our algorythm is working incorrect.
//		return false;
//	}
//	catch (...)
//	{
//		//Print Error Message on Console (unknown error).
//		EConsole::PrintScreen("[[ERROR : Invalid error! ]]");
//		//Return false value means our algorythm is working incorrect.
//		return false;
//	}
//}
//
//bool SampleBrainBit::RemoveSignalCallbackBrainBit_Spectrum()
//{
//	try
//	{
//		//Check if our sensor is empty or not.
//		if (_sensor == nullptr)
//			throw std::invalid_argument("Null sensor!");
//
//		if (_lSignalDataSpectrumHandle == 0)
//		{
//			throw std::invalid_argument("Null Signal Data for Spectrum handle!");
//		}
//
//		removeSignalDataCallbackBrainBit(_lSignalDataSpectrumHandle);
//		_lSignalDataSpectrumHandle = 0;
//
//		return true;
//	}
//	catch (std::exception error)
//	{
//		//Print Error Message on Console.
//		EConsole::PrintScreen("[[ERROR : ", error.what(), " ]]");
//		//Return false value means our algorythm is working incorrect.
//		return false;
//	}
//	catch (...)
//	{
//		//Print Error Message on Console (unknown error).
//		EConsole::PrintScreen("[[ERROR : Invalid error! ]]");
//		//Return false value means our algorythm is working incorrect.
//		return false;
//	}
//}
