#pragma once
#include <string>
#include "TuringMachineBase.h"

enum PosType
{
	Custom, End, None
};

class TuringTest
{
protected:
	std::string path, argument, answer;
	int position;

public:
	void Work(TuringMachineBase&, std::string, PosType, int);
	TuringTest() {}
};

