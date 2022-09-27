#include <iostream>
#include <string>
#include "Tu21.h"
#include "TuringTest.h"

int main()
{
    Tu21* test = new Tu21("*110110101*011101001*", 20);
    //std::cout << test->Machine();

    std::string Path;
    std::cout << "Enter filepath: ";
    std::cin >> Path;
    TuringTest* TestMachine = new TuringTest();
    TestMachine->Work(*test, Path, PosType::End, 0);
    std::system("pause");
    delete TestMachine;
    delete test;
}
