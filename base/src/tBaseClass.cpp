#include <iostream>

#include "inc/tBaseClass.h"

BaseClass::BaseClass()
{
    baseVariable = 5;
    std::cout << "BaseClass Default Ctor()" << std::endl;
}

BaseClass::BaseClass(int& bV)
{
    baseVariable = bV;
    std::cout << "BaseClass Default Ctor()" << std::endl;
}

BaseClass::~BaseClass()
{
    std::cout << "BaseClass Defaul Dtor()" << std::endl;
}

void BaseClass::SetBaseBaseVariable(int& bV) {
    baseVariable = bV;
}

int BaseClass::GetBaseVariable() {
    return baseVariable;
}

void BaseClass::Debug() {
    std::cout << "baseVariable: " << baseVariable << std::endl;
}


void BaseClass::vFn() {
    std::cout << "BaseClass vBaseFn Invoked" << std::endl;
}
