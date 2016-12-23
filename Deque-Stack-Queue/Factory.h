#include "StationInterface.h"
#pragma once

/*
	Creates and returns an object whose class extends StationInterface.
*/
class Factory
{
public:
	static StationInterface* createStation();
};
