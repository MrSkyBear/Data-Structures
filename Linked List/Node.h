/*
 * Node.h
 * Author: kevinmj
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>

using namespace std;

class Node
{
	public:
		Node(int data_value);
		virtual ~Node();

		Node* next;
		int data;
};

#endif /* NODE_H_ */
