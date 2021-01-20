#include <iostream>
#include "DemoConstCast.h"

using namespace std;

void DemoConstCast::demo()
{
    const int a = 10;
    const int *pA = &a;

    cout <<" a : " <<a<<endl;
    cout << " *pA : "<<*pA<<endl;

    int *pAnc = const_cast<int*>(pA);
    *pAnc = 20;
    cout <<" a : " <<a<<endl;       //value is 10 as optimization will replace A as 10 at compileTime only
    cout << " *pA : "<<*pA<<endl;

    //Above code should not be done as its misleading code we should not be
    //using const_cast for pointer to const variable.
    //Instead it should be used for the pointer which is const but points to non cost variable.

    int b = 30;
    const int *pB  = &b;

    cout <<" b : " <<b<<endl;
    cout << " *pB : "<<*pB<<endl;

    int *pBnc = const_cast<int*>(pB);
    *pBnc = 20;
    cout <<" b : " <<b<<endl;       //value is 10 as optimization will replace A as 10 at compileTime only
    cout << " *pB : "<<*pB<<endl;

    //use it when some API might need no Const argument but dont modify value.
}