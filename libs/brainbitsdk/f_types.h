#ifndef F_TYPES_H
#define F_TYPES_H

#include "lib_export.h"
#include <stdint.h>
typedef int TFilterID;

enum FilterType : uint8_t
{
	FtHP = 0,
	FtLP = 1,
	FtBandStop = 2,
	FtBandPass = 3,
	FtNone = 4
};

typedef struct _FilterParam
{
	enum FilterType type;
	int samplingFreq;
	double cutoffFreq;
}FilterParam;

#endif

