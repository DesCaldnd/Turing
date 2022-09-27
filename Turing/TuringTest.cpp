#include "TuringTest.h"
#include <fstream>
#include <iostream>

void TuringTest::Work(TuringMachineBase& testMachine, std::string Path, PosType posType, int Position)
{
	std::ifstream File(Path);
	int right = 0, overall = 0;

	while (std::getline(File, argument, ' '))
	{
		std::getline(File, answer);
		overall++;
		testMachine.SetString(argument);

		int position = 0;

		switch (posType)
		{
		case Custom:
			position = Position;
			break;
		case End:
			position = int(argument.length()) - 1;
			break;
		case None:
			position = testMachine.GetPosition();
			break;
		}

		testMachine.SetPosition(position);

		std::string res = testMachine.Machine();

		if (res == answer)
		{
			std::cout << "Test " << overall << " completed successfully!" << std::endl;
			right++;
		}
		else
			std::cout << "Test " << overall << "  completed with error, answer is: " << res << " right is: " << answer << std::endl;
	}

	File.close();

	std::cout << "Passed " << right << " of " << overall << " test(s).\n" << double(right) / overall * 100 << "% of success." << std::endl;
}
