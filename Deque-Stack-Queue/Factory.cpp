#include "Factory.h"
#include "StationInterface.h"
#include "Station.h"

using namespace std;

/*
	Creates and returns an object whose class extends StationInterface.
*/
StationInterface* Factory::createStation()
{
	return new Station();
}
