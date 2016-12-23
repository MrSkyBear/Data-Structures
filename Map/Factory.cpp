#include "Factory.h"
#include "Mimic.h"

using namespace std;

/*
	Creates and returns an object whose class extends MimicInterface.
*/
MimicInterface* Factory::createMimic()
{
	return new Mimic();
}
