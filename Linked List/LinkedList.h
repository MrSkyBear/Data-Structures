/*
 * LinkedList.h
 * Author: kevinmj
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkedListInterface.h"
#include "Node.h"

using namespace std;

class LinkedList : public LinkedListInterface
{
	public:
		LinkedList();
		virtual ~LinkedList();

		void insertHead(int value);
		void insertTail(int value);
		void insertAfter(int value, int insertionNode);
		void remove(int value);
		void clear();
		int at(int index);
		int size();
		bool exists(int data_check);

		Node* head;
		int list_size;
		Node* current;
};

#endif /* LINKEDLIST_H_ */
