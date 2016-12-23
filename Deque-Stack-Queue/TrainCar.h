#pragma once

using namespace std;

class TrainCar
{
public:
	TrainCar(int car);
	~TrainCar();

	int ID_NUMBER;
	TrainCar* next;
};