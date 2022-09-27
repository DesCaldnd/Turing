#pragma once
#include <string>

class TuringMachineBase
{
protected:
	int q = 0, position = 0;
	std::string str;

public:
	virtual std::string Machine() { return str; };

	inline std::string GetString() { return str; }
	virtual inline void SetString(std::string str) { this->str = str; }

	inline int GetPosition() { return position; };
	virtual inline void SetPosition(int position) { this->position = position; }

	TuringMachineBase(std::string, int);
};

