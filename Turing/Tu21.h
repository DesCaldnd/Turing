#pragma once
#include "TuringMachineBase.h"

class Tu21 :
    public TuringMachineBase
{
public:
    virtual std::string Machine();
    Tu21(std::string str, int position) : TuringMachineBase(str, position){}
};

