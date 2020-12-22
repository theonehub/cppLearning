#include <iostream>
#include <ostream>

#include "inc/tBaseClass.h"

int main()
{
    BaseClass *bc = new BaseClass();
    int var = 10;
    bc->SetBaseBaseVariable(var);

    std::cout << bc->GetBaseVariable() << std::endl;
    delete bc;
    return 0;
}
