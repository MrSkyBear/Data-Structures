#include "TrainStack.h"
#include <string>

using namespace std;

TrainStack::TrainStack()
{
	STACK_CAPACITY = 5;
	stack_size = 0;
	top = NULL;
	bottom = NULL;
}

TrainStack::~TrainStack(){}

void TrainStack::push(int car)
{
	if (stack_size == 0)
	{
		top = new TrainCar(car);
		bottom = top;
		++stack_size;
		return;
	}

	if (stack_size == 1 && stack_size < STACK_CAPACITY)
	{
		TrainCar* temp = new TrainCar(car);
		top->next = temp;
		bottom = top;
		top = temp;
		++stack_size;
		return;
	}

	if (stack_size > 1 && stack_size < STACK_CAPACITY)
	{
		TrainCar* temp = new TrainCar(car);
		top->next = temp;
		top = temp;
		++stack_size;
		return;
	}

	else
	{
		return;
	}
}

int TrainStack::pop()
{
	if (bottom != top)
	{
		int removed_id = top->ID_NUMBER;
		TrainCar* temp = bottom;

		while (temp->next != top)
		{
			temp = temp->next;
		}

		TrainCar* temp_delete = top;
		top = temp;
		delete temp_delete;
		--stack_size;
		return removed_id;
	}

	else
	{
		int removed_id = top->ID_NUMBER;
		TrainCar* temp = top;
		delete temp;
		--stack_size;

		top = NULL;
		bottom = NULL;

		return removed_id;
	}
}

int TrainStack::ShowTop()
{
	return top->ID_NUMBER;
}

int TrainStack::Size()
{
	return stack_size;
}

bool TrainStack::exists(int car)
{
	TrainCar* iterator = bottom;
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