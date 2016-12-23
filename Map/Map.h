#pragma once
#include <vector>
#include <string>
#include "Map_Node.h"
#include <iostream>

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void addNode(string key, vector<string> values);
	
	vector<Map_Node> Nodes;
	int size;
};