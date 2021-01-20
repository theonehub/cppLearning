#include <iostream>
#include "DemoReinterpretCast.h"

using namespace std;
//https://www.youtube.com/watch?v=JBvEfB_F66o
// class A {
//     public:
//     void DisplayA()
//     {
//         cout << "DisplayA" <<endl;
//     }
// };

// class B {
//     private:
//         int b = 10;
//     public:
//     void DisplayB1()
//     {
//         cout << "DisplayB1 " <<endl;
//     }

//     void DisplayB()
//     {
//         cout << "DisplayB" <<endl;
//     }
// };

// void DemoReinterpretCast::demo()
// {
//     A *a = new A();
//     B *b = new B();
//     B *newB = reinterpret_cast<B*>(a);//Compilation passes but will be problem at runtime.

//     newB->DisplayB();
// }

struct myStruct {
    int x;
    int y;
    char c;
    bool b;
};

void DemoReinterpretCast::demo() { 
    myStruct s;
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;

    int *p = reinterpret_cast<int*>(&s);

    cout << "x :" << *p <<endl;
    cout << "y :" << *++p <<endl;

    char *c =  reinterpret_cast<char*>(++p);
    cout << "c : " << *c <<endl;
    bool b = *(reinterpret_cast<bool*>(++c));
    cout << "b : "<< b <<endl;
}