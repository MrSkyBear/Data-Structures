#include "Station.h"

using namespace std;

Station::Station()
{
	current = NULL;
}

Station::~Station(){}

bool Station::addToStation(int car)
{
	if (current != NULL)
	{
		return false;
	}

	if (car < 0)
	{
		return false;
	}

	if (my_stack.exists(car))
	{
		return false;
	}

	if (my_deque.exists(car))
	{
		return false;
	}

	if (my_queue.exists(car))
	{
		return false;
	}

	current = new TrainCar(car);
	return true;
}

int Station::showCurrentCar()
{
	if (current == NULL)
	{
		return -1;
	}

	else
	{
		return current->ID_NUMBER;
	}
}

bool Station::removeFromStation()
{
	if (current == NULL)
	{
		return false;
	}

	else
	{
		TrainCar* temp = current;
		current = NULL;
		delete temp;
		return true;
	}
}

bool Station::addToStack()
{
	if (my_stack.Size() < 5 && current != NULL)
	{
		my_stack.push(current->ID_NUMBER);
		current = NULL;
		return true;
	}

	else
	{
		return false;
	}
}

bool Station::removeFromStack()
{
	if (current == NULL && my_stack.Size() > 0)
	{
		current = new TrainCar(my_stack.pop());
		return true;
	}

	else
	{
		return false;
	}
}

int Station::showTopOfStack()
{
	if (my_stack.Size() > 0)
	{
		return my_stack.ShowTop();
	}

	else
	{
		return -1;
	}
}

int Station::showSizeOfStack()
{
	return my_stack.Size();
}

bool Station::addToQueue()
{
	if (my_queue.Size() < 5 && current != NULL)
	{
		my_queue.enqueue(current->ID_NUMBER);
		current = NULL;
		return true;
	}

	else
	{
		return false;
	}
}

bool Station::removeFromQueue()
{
	if (current == NULL && my_queue.Size() > 0)
	{
		current = new TrainCar(my_queue.dequeue());
		return true;
	}

	else
	{
		return false;
	}
}

int Station::showTopOfQueue()
{
	if (my_queue.Size() > 0)
	{
		return my_queue.ShowFront();
	}

	else
	{
		return -1;
	}
}

int Station::showSizeOfQueue()
{
	return my_queue.Size();
}

bool Station::addToDequeLeft()
{
	if (my_deque.Size() < 5 && current != NULL)
	{
		my_deque.InsertLeft(current->ID_NUMBER);
		current = NULL;
		return true;
	}
	
	else
	{
		return false;
	}
}

bool Station::addToDequeRight()
{
	if (my_deque.Size() < 5 && current != NULL)
	{
		my_deque.InsertRight(current->ID_NUMBER);
		current = NULL;
		return true;
	}
	else
	{
		return false;
	}
}

bool Station::removeFromDequeLeft()
{
	if (current == NULL && my_deque.Size() > 0)
	{
		current = new TrainCar(my_deque.RemoveLeft());
		return true;
	}

	else
	{
		return false;
	}
}

bool Station::removeFromDequeRight()
{
	if (current == NULL && my_deque.Size() > 0)
	{
		current = new TrainCar(my_deque.RemoveRight());
		return true;
	}

	else
	{
		return false;
	}
}

int Station::showTopOfDequeLeft()
{
	if (my_deque.Size() > 0)
	{
		return my_deque.ShowLeft();
	}

	else
	{
		return -1;
	}
}

int Station::showTopOfDequeRight()
{
	if (my_deque.Size() > 0)
	{
		return my_deque.ShowRight();
	}

	else
	{
		return -1;
	}
}

int Station::showSizeOfDeque()
{
	return my_deque.Size();
}