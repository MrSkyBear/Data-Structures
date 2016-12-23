#include "Mimic.h"
#include "Map.h"
#include <string>
#include <iostream>

using namespace std;

Mimic::Mimic(){}

Mimic::~Mimic(){}

void Mimic::createMap(string input)
{
	string prefix1 = "";
	string prefix2 = "";
	string suffix = "";
	string concatenated_key = "";
	vector<string> items;

	stringstream ss;
	ss.str(input);

	int count = 0;

	while (!(ss.eof()))
	{
		if (count == 0)
		{
			ss >> prefix1;
			ss >> prefix2;
			ss >> suffix;
			++count;
		}

		else
		{
			prefix1 = prefix2;
			prefix2 = suffix;
			ss >> suffix;
		}

		ostringstream result;
		result << prefix1 << " " << prefix2;
		
		concatenated_key = result.str();
		vector<string> new_items;
		new_items.push_back(suffix);
		my_map.addNode(concatenated_key, new_items);
	}

	prefix1 = prefix2;
	prefix2 = suffix;
	suffix = "THE_END";
	ostringstream final_result;
	final_result << prefix1 << " " << prefix2;
	vector<string> final_items;
		
	concatenated_key = final_result.str();
	final_items.push_back(suffix);
	my_map.addNode(concatenated_key, final_items);
}

vector<string> Mimic::getSuffixList(string prefix)
{
	vector<string> not_found; //empty vector to return if not found
	vector<string> found_items; //list of suffixes for associated prefix
	bool found = false;

	for (int i = 0; i < my_map.Nodes.size(); i++)
	{
		if (my_map.Nodes[i].key == prefix)
		{
			found = true;
			for (int x = 0; x < my_map.Nodes[i].values.size(); x++)
			{
				found_items.push_back(my_map.Nodes[i].values[x]);
			}
		}
	}

	if (!found)
	{
		return not_found;
	}

	else
	{
		return found_items;
	}
}

string Mimic::generateText()
{
	int count = 0;
	int position = 0;
	string prefix = my_map.Nodes[0].key;
	ostringstream final_result;
	string suffix = "";

	final_result << prefix;
	int random = rand() % my_map.Nodes[position].values.size();
	suffix = my_map.Nodes[position].values[random];
	
	final_result << " " << suffix;

	while (suffix != "THE_END")
	{
		stringstream ss;
		ss.str(prefix);
		string garbage = "";
		ss >> garbage;
		ss >> prefix; //gets second word of previous prefix for new prefix

		ostringstream final_prefix;
		final_prefix << prefix << " " << suffix; //second word of last prefix and suffix form new prefix

		prefix = final_prefix.str();
		for (int i = 0; i < my_map.Nodes.size(); i++) //searches list of nodes for that prefix
		{
			if (my_map.Nodes[i].key == prefix)
			{
				position = i;
			}
		}

		random = rand() % my_map.Nodes[position].values.size();
		suffix = my_map.Nodes[position].values[random];

		if (suffix == "THE_END")
		{
			string created_string = final_result.str();
			return created_string;
		}

		else
		{
			final_result << " " << suffix;
		}
	}
}
