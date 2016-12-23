/*
 * Node.cpp
 * Author: kevinmj
 */

#include "Node.h"

using namespace std;

Node::Node(int data_value)
{
	next = NULL;
	data = data_value;
}

Node::~Node() 
{

}

