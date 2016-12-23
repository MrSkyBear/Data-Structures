#pragma once
#include <vector>
#include <string>

using namespace std;

class Map_Node
{
public:

	Map_Node(string the_key, vector<string> the_values);
	~Map_Node();

	string key;
	vector<string> values;

};