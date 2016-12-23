#pragma once

#include "TrainCar.h"

using namespace std;

class TrainStack
{
public:
	TrainStack();
	~TrainStack();

	void push(int car);
	int pop();
	int ShowTop();
	int Size();
	bool exists(int car);

protected:
	int STACK_CAPACITY;
	int stack_size;

	TrainCar* top;
	TrainCar* bottom;
};