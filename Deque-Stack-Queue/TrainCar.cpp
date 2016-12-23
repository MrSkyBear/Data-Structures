
#include "TrainCar.h"
#include <string>

using namespace std;

TrainCar::TrainCar(int car)
{
	ID_NUMBER = car;
	next = NULL;
}

TrainCar::~TrainCar(){}