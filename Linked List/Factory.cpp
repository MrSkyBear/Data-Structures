#include "Factory.h"
#include "LinkedList.h"
#include "LinkedListInterface.h"
#include "Node.h"

/*
	Creates and returns an object whose class extends LinkedListInterface.
*/
LinkedListInterface * Factory::getLinkedList()
{
	return new LinkedList();//Modify this line
}
