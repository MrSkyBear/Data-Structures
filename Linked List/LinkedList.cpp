/*
 * LinkedList.cpp
 * Author: kevinmj
 */

#include "LinkedList.h"
#include "Node.h"

using namespace std;

LinkedList::LinkedList(
{
	head = NULL;
	list_size = 0;
	current = head;
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::insertHead(int value)
{
	if (value >= 0 && !exists(value))
	{
		current = head;
		if (head != NULL)
		{
			Node* temp = head;
			head = new Node(value);
			head->next = temp;
			++list_size;
		}

		else
		{
			head = new Node(value);
			++list_size;
		}
	}

	else
	{
		return;
	}
}

void LinkedList::insertTail(int value)
{
	if (value >= 0 && !exists(value))
	{
		current = head;

		if (head != NULL)
		{

			while (current->next != NULL)
			{
				current = current->next;
			}

			Node* temptail = new Node(value);
			current->next = temptail;
			++list_size;
		}

		else
		{
			head = new Node(value);
			++list_size;
		}
	}
	else
	{
		return;
	}
}

void LinkedList::insertAfter(int value, int insertionNode)
{
	current = head;

	if (exists(insertionNode) && value >= 0 && !exists(value))
	{
		current = head;
		while (current != NULL)
		{
			if (current->data == insertionNode)
			{
				Node* temp_insert = new Node(value);
				temp_insert->next = current->next;
				current->next = temp_insert;
				++list_size;
			}

			current = current->next;
		}

	}
	else
	{
		return;
	}
}

void LinkedList::remove(int value)
{
	current = head;

	if (exists(value) == true)
	{
		current = head;

		while (current->data != value) //finds node with given value
		{
			current = current->next;
		}

		if (current == head && head->next != NULL) //if node to delete is head and not the only node in list
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			--list_size;
			return;
		}

		if (current == head && head->next == NULL) //if node is head and the only node in the list
		{
			Node* temp = head;
			delete temp;
			--list_size;
			return;
		}

		if (current != head && current->next != NULL) //if node is any other node besides head or last node
		{
			current = head;
			while (current->next->data != value)
			{
				current = current->next;
			}

			Node* temp_erase = current->next;
			current->next = current->next->next;
			delete temp_erase;
			--list_size;
			return;

		}

		if (current != head && current->next == NULL) //if node is last node in list
		{
			current = head;
			while (current->next->data != value)
			{
				current = current->next;
			}

			Node* temp = current->next;
			current->next = NULL;
			delete temp;
			--list_size;
			return;

		}
	}
	else
	{
		return;
	}
}

void LinkedList::clear()
{
	while (head != NULL)
	{
		Node* temp_clear = head;
		head = head->next;
		delete temp_clear;
	}

	list_size = 0;
}

int LinkedList::at(int index)
{
	current = head;

	if (index > (list_size-1) || index < 0)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		return current->data;
	}
}

int LinkedList::size()
{
	return list_size;
}

bool LinkedList::exists(int data_check)
{
	current = head;

		while (current != NULL)
		{
			if (current->data == data_check)
			{
				return true;
			}

			else
			{
				current = current->next;
			}
		}

		return false;
}


