#pragma once
#include "StationInterface.h"
#include "TrainDeque.h"
#include "TrainStack.h"
#include "TrainQueue.h"
#include "TrainCar.h"
#include <string>

using namespace std;

class Station : public StationInterface
{
public: 
	
	Station();
	~Station();

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();	
	
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();
	
	bool addToQueue();
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();
	
	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();

protected:
	TrainStack my_stack;
	TrainQueue my_queue;
	TrainDeque my_deque;

	TrainCar* current;
};