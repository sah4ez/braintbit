#pragma once

#include "sdk_api.h"
#include "log.h"
#include <clickhouse/client.h>

void SignalCallback(Sensor* sensor, BrainBitSignalData* data, int32_t size, void* userData)
{
    clickhouse::Client* client = (clickhouse::Client*)userData;
    clickhouse::Block block;

    auto dt = std::make_shared<clickhouse::ColumnDateTime64>();
    auto o1 = std::make_shared<clickhouse::ColumnFloat64>();
    auto o2 = std::make_shared<clickhouse::ColumnFloat64>();
    auto t3 = std::make_shared<clickhouse::ColumnFloat64>();
    auto t4 = std::make_shared<clickhouse::ColumnFloat64>();

	for (int i = 0; i < size; i++)
	{
        auto microsecondsUTC = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::cout << microsecondsUTC;
        // std::cout << std::endl;
        std::cout << "," <<data[i].PackNum;

        std::cout << "," <<data[i].O1;
        // std::cout << std::endl;

        std::cout << "," << data[i].O2;
        // std::cout << std::endl;

        std::cout << "," <<data[i].T3;
        // std::cout << std::endl;

        std::cout << "," << data[i].T4;
        std::cout << std::endl;

        dt->Append(microsecondsUTC);
        o1->Append(data[i].O1);
        o2->Append(data[i].O2);
        t3->Append(data[i].T3);
        t4->Append(data[i].T4);
	}

    block.AppendColumn("dt64", dt);
    block.AppendColumn("o1", o1);
    block.AppendColumn("o2", o2);
    block.AppendColumn("t3", t3);
    block.AppendColumn("t4", t4);

    client->Insert("default.brainbit", block);
}
