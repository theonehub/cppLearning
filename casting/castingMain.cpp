#include <iostream>
#include "demoStaticCast.h"
#include "DemoReinterpretCast.h"
#include "DemoConstCast.h"

using namespace std;

int main(void)
{
    demoStaticCast dSC;
    //static_cast
    dSC.demo();

    DemoReinterpretCast dIC;
    dIC.demo();

    DemoConstCast dCC;
    dCC.demo();

}