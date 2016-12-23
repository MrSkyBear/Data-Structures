#pragma once
#include "LinkedListInterface.h"

using namespace std;

/*
	Creates and returns an object whose class extends LinkedListInterface.
*/
class Factory
{
	public:
		static 	LinkedListInterface * getLinkedList();
};
