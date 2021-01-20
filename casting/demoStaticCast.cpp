#include <iostream>
#include "demoStaticCast.h"

using namespace std;

//static_cast is compile time cast. 

demoStaticCast::demoStaticCast()
{
    cout << "demoStaticCast Default cTor()" << std::endl;
}

demoStaticCast::~demoStaticCast()
{
    cout << "demoStaticCast Default dTor()" << std::endl;
}

class Int {
    int x;
    public:
        Int(int x=0):x{x} 
        {
            cout << "Conversion constructor" <<endl;
        }

        operator string() { 
            cout << "Conversion Operator" <<endl;
            return to_string(x);
        }
};

class IntDrived1 :private Int{

};

class IntDrived2 :public Int{

};

class IntDrived3 :public Int{

};

bool demoStaticCast::demo()
{
    char varC;
    int var = 10;
    varC = var; //its a problem
    cout << "varC " << varC << endl;


    varC = static_cast<char>(var);

    Int obj(3);

    string str = static_cast<string>(obj);
    str = 30;

    char c;
    int *pIntC = (int*)&c;      //C types conversion without error.
    *pIntC = 5;

    //int *pIntStatic = static_cast<int*>&c;      //Compilation issue 


    IntDrived1 d1;

    Int *bIntC = (Int*)&d1;

    //Int *bIntS = static_cast<Int*>(&d1);      //Compilation error

    IntDrived2 d2;
    IntDrived2 d3;

    Int* bp1 = static_cast<Int*>(&d2);
    Int* bp2 = static_cast<Int*>(&d3);

    IntDrived2 *pd2 = static_cast<IntDrived2*>(bp2);    //DownCast is reverse without any compilation
    IntDrived3 *pd3 = static_cast<IntDrived3*>(bp1);    //error but could turn into problem btr use dynamic_cast


    int i = 10;
    void *v = static_cast<void*>(&i);
    int* pI = static_cast<int*>(v);
}