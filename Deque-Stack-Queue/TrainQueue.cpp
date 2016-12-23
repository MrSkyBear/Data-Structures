#include "TrainQueue.h"
#include <string>

using namespace std;

TrainQueue::TrainQueue()
{
	QUEUE_CAPACITY = 5;
	queue_size = 0;
	front = NULL;
	rear = NULL;
}

TrainQueue::~TrainQueue(){}

void TrainQueue::enqueue(int car)
{
	if (queue_size == 0)
	{
		front = new TrainCar(car);
		rear = front;
		++queue_size;
		return;
	}

	if (queue_size > 0 && queue_size < QUEUE_CAPACITY)
	{
		TrainCar* temp = new TrainCar(car);
		rear->next = temp;
		rear = temp;
		++queue_size;
		return;
	}

	else
	{
		return;
	}
}

int TrainQueue::dequeue()
{
	if (queue_size == 1)
	{
		TrainCar* temp = front;
		int removed_id = front->ID_NUMBER;
		delete temp;
		--queue_size;

		front = NULL;
		rear = NULL;
		
		return removed_id;
	}

	if (queue_size > 1)
	{
		TrainCar* temp = front;
		int removed_id = temp->ID_NUMBER;
		front = front->next;
		delete temp;
		--queue_size;

		return removed_id;
	}
}

int TrainQueue::ShowFront()
{
	return front->ID_NUMBER;
}

int TrainQueue::Size()
{
	return queue_size;
}

bool TrainQueue::exists(int car)
{
	TrainCar* iterator = front;
	while (iterator != NULL)
	{
		if (iterator->ID_NUMBER == car)
		{
			return true;
		}

		iterator = iterator->next;
	}

	return false;
}