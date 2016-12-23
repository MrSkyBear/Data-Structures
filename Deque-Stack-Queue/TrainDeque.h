#pragma once

#include "TrainCar.h"
#include <string>

using namespace std;

class TrainDeque
{
public:

	TrainDeque();
	~TrainDeque();

	void InsertLeft(int car);
	void InsertRight(int car);
	int RemoveLeft();
	int RemoveRight();
	int ShowLeft();
	int ShowRight();
	int Size();
	bool exists(int car);

protected:
	
	int DEQUE_CAPACITY;
	TrainCar* left_most;
	TrainCar* right_most;

	int deque_size;
};