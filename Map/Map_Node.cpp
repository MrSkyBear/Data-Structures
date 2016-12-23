#include "Map_Node.h"

using namespace std;

Map_Node::Map_Node(string the_key, vector<string> the_values)
{
	key = the_key;
	values = the_values;
}

Map_Node::~Map_Node(){}