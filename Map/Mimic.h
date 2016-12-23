#pragma once
#include "MimicInterface.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Mimic : public MimicInterface
{
public:
	Mimic();
	~Mimic();

	void createMap(string input);
	vector<string> getSuffixList(string prefix);
	string generateText();
	Map my_map;
};