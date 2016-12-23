#pragma once
#include "ExpressionManagerInterface.h"
using namespace std;

/*
	Creates and returns an object whose class extends ExpressionManagerInterface.
*/

class Factory
{
	public:
		static ExpressionManagerInterface * createManager();
};
