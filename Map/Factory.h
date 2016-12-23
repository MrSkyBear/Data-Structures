#include "MimicInterface.h"
#pragma once

/*
	Creates and returns an object whose class extends MimicInterface.
*/
class Factory
{
public:
	static MimicInterface* createMimic();
};
