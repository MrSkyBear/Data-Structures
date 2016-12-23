# include "Map.h"

using namespace std;

Map::Map()
{
	size = 0;
}

Map::~Map(){}

void Map::addNode(string new_key, vector<string> new_values)
{
	bool found = false;

	for (int i = 0; i < Nodes.size(); i++)
	{
		if (Nodes[i].key == new_key)
		{
			for (int j = 0; j < new_values.size(); j++)
			{
				Nodes[i].values.push_back(new_values[j]);
				found = true;
			}
		}
	}

	if (!found)
	{
		Nodes.push_back(Map_Node(new_key, new_values));
		++size;
	}
}