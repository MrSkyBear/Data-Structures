#include "Factory.h"
#include "ExpressionManagerInterface.h"
#include "ExpressionManager.h"

using namespace std;

/*
	Creates and returns an object whose class extends ExpressionManagerInterface.
*/
ExpressionManagerInterface* Factory::createManager()
{
	return new ExpressionManager();
}