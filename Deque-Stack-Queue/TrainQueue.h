#pragma once
#include "TrainCar.h"

using namespace std;

class TrainQueue
{
public:
	TrainQueue();
	~TrainQueue();

	void enqueue(int car);
	int dequeue();
	int ShowFront();
	int Size();
	bool exists(int car);

protected:
	int QUEUE_CAPACITY;
	TrainCar* front;
	TrainCar* rear;

	int queue_size;

};