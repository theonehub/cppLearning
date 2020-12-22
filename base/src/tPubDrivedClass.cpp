#include "inc/tPubDrivedClass.h"
#include <iostream>

PubDrivedClass::PubDrivedClass()
{
    std::cout << "Drived Class Ctor() Invoked" << std::endl;
}

PubDrivedClass::~PubDrivedClass()
{
    std::cout << "Drived Class Dtor() Invoked" << std::endl;
}

void PubDrivedClass::Debug()
{
    std::cout << "Drived Class Debug Invoked" << std::endl;
}

void PubDrivedClass::vFn()
{
    std::cout << "Drived Class vFn() Invoked" << std::endl;
}
