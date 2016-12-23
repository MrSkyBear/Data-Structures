#include "TrainDeque.h"
#include <iostream>

using namespace std;

TrainDeque::TrainDeque()
{
	DEQUE_CAPACITY = 5;
	left_most = NULL;
	right_most = NULL;
	deque_size = 0;
}

TrainDeque::~TrainDeque(){}

void TrainDeque::InsertLeft(int car)
{
	if (deque_size == 0)
	{
		left_most = new TrainCar(car);
		right_most = left_most;
		++deque_size;
		return;
	}

	if (deque_size > 0 && deque_size < DEQUE_CAPACITY)
	{
		TrainCar* temp = new TrainCar(car);
		temp->next = left_most;
		left_most = temp;
		++deque_size;
		return;
	}

	else
	{
		return;
	}
}

void TrainDeque::InsertRight(int car)
{
	if (deque_size == 0)
	{
		left_most = new TrainCar(car);
		right_most = left_most;
		++deque_size;
		return;
	}

	if (deque_size > 0 && deque_size < DEQUE_CAPACITY)
	{
		TrainCar* temp = new TrainCar(car);
		right_most->next = temp;
		right_most = temp;
		++deque_size;
		return;
	}

	else
	{
		return;
	}
}

int TrainDeque::RemoveLeft()
{

	if (left_most != NULL && left_most->next == NULL)
	{
		TrainCar* temp = left_most;
		int removed_id = temp->ID_NUMBER;
		delete temp;
		--deque_size;
		left_most = NULL;
		return removed_id;
	}

	if (left_most != NULL && left_most->next != NULL)
	{
		TrainCar* temp = left_most;
		int removed_id = temp->ID_NUMBER;
		left_most = left_most->next;
		delete temp;
		--deque_size;
		return removed_id;
	}
}

int TrainDeque::RemoveRight()
{
	if (right_most != NULL && left_most != right_most)
	{
		TrainCar* current = left_most;
		while (current->next != right_most)
		{
			current = current->next;
		}

		TrainCar* temp_delete = right_most;
		int removed_id = temp_delete->ID_NUMBER;
		right_most = current;
		delete temp_delete;
		--deque_size;
		return removed_id;
	}

	if (left_most == right_most)
	{
		TrainCar* temp = right_most;
		int removed_id = temp->ID_NUMBER;
		delete temp;
		--deque_size;
		return removed_id;
	}
}

int TrainDeque::ShowLeft()
{
	return left_most->ID_NUMBER;
}

int TrainDeque::ShowRight()
{
	return right_most->ID_NUMBER;
}

int TrainDeque::Size()
{
	return deque_size;
}

bool TrainDeque::exists(int car)
{
	TrainCar* iterator = left_most;
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