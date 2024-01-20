#include "main_scanner.h"
#include "main_brainbit.h"
#include "main_filters.h"
#include "log.h"

#include <typeinfo>
#include <sdk_api.h>
#include <clickhouse/client.h>
#include <iostream>
#include <chrono>

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

    clickhouse::Client client(clickhouse::ClientOptions().SetHost("localhost"));
	EConsole::PrintLog("run function");
	//Compile code to connect device & control
	SampleBrainBitFunction(brainbit, &client);
}

// void BrainBitFiltersFunction()
// {
// 	//Create Sensor to connect to device (LEBrainBit)
// 	Sensor* brainbit = SampleScannerFunction();
// 
// 	//If object is null, show information of not found device and stop code
// 	if (brainbit == nullptr)
// 	{
// 		EConsole::PrintLog("Can't find device!");
// 		return;
// 	}
// 
// 	EConsole::PrintLog("start scanner");
// 	//Compile code to using lib 'filters'
// 	SampleBrainBitFilters(brainbit);
// }

int main()
{

    clickhouse::Client client(clickhouse::ClientOptions().SetHost("localhost"));
     /// Create a table.
    client.Execute("CREATE TABLE IF NOT EXISTS default.brainbit (dt64 DateTime64(6, 'Europe/Moscow'), o1 Float64, o2 Float64, t3 Float64, t4 Float64) ENGINE = Memory");
    std::cout << "create table\n";

    /*{
        clickhouse::Block block;

        auto dt = std::make_shared<clickhouse::ColumnDateTime64>(6);
        auto o1 = std::make_shared<clickhouse::ColumnFloat64>();
        auto o2 = std::make_shared<clickhouse::ColumnFloat64>();
        auto t3 = std::make_shared<clickhouse::ColumnFloat64>();
        auto t4 = std::make_shared<clickhouse::ColumnFloat64>();
        for (auto i = 0; i < 10; i++) {
            auto microsecondsUTC = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            std::cout << microsecondsUTC << '\n';
            dt->Append(microsecondsUTC);

            o1->Append(0.0);
            o2->Append(0.0);
            t3->Append(0.0);
            t4->Append(0.0);

        }
        block.AppendColumn("dt64", dt);
        block.AppendColumn("o1", o1);
        block.AppendColumn("o2", o2);
        block.AppendColumn("t3", t3);
        block.AppendColumn("t4", t4);
        client.Insert("default.brainbit", block);
    }*/

    // json object = { { "msg", "start" }, { "p", 1 } };
    // std::cout << object << '\n';
    BrainBitFunction();
	// BrainBitFiltersFunction();
    // object = { { "msg", "end" }, { "p", 2 } };
    std::cout << "hello2" << '\n';
    return 0;
}
