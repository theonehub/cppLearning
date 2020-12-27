#include <iostream>
#include "tmpltBase.h"
#include "MyInt.h"

int main(void)
{
    Calculator<int> obj(10,20);
    obj.add();

    MyInt a(30);
    MyInt b(60);
    Calculator<MyInt> obj1(a, b);
    obj1.add();
}