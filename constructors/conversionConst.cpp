#include <iostream>

using namespace std;

// ConversionConstructor are normal constructor not defined as explicit 
// Incase of MyObjectSingle obj = 20; implicitly constructor is invoked 
//  
//==================================================================
// class MyObjectSingle
// {
//     private:
//         int x;
//         int y;
//     public:
//         explicit MyObjectSingle(int p):x(p),y(p)     //compilation error
//         MyObjectSingle(int p):x(p),y(p)
//         {
//             cout << "MyObjectSingle default ctor()" << endl;
//         }

//         void display()
//         {
//             cout << "X : "<<x<<" Y : "<<y<<endl;
//         }
// };

// int main()
// {
//     MyObjectSingle obj(10);
//     obj.display();

//     //Single Parameter Conversion Constructor
//     obj = 20;
//     obj.display();
//     return 0;
// }

//==================================================================
//Using Object for ArgClass

// class ArgClass
// {
//     public:
//         int a;
//         void display()
//         {
//             cout << a <<endl;
//         }
// };

// class MyObjectSingle
// {
//     private:
//         ArgClass ac;
//     public:
//         MyObjectSingle(ArgClass& argAc)
//         {
//             ac = argAc;
//         }
//         void display()
//         {
//             ac.display();
//         }
// };

// int main(void)
// {
//     ArgClass ac;
//     ac.a = 10;
//     ac.display();
//     MyObjectSingle myObj(ac);
//     myObj.display();

//     ArgClass ac2;
//     ac2.a = 20;

//     myObj = ac2;
//     myObj.display();
//     return 0;
// }

//==================================================================
//Using Pointer for ArgClass

// class ArgClass
// {
//     public:
//         int a;
//         void display()
//         {
//             cout << a <<endl;
//         }
// };

// class MyObjectSingle
// {
//     private:
//         ArgClass *ac;
//     public:
//         MyObjectSingle(ArgClass* argAc)
//         {
//             ac = argAc;
//         }
//         void display()
//         {
//             ac->display();
//         }
// };

// int main(void)
// {
//     ArgClass ac;
//     ac.a = 10;
//     ac.display();
//     MyObjectSingle myObj(&ac);
//     myObj.display();

//     ArgClass ac2;
//     ac2.a = 20;

//     myObj = &ac2;
//     myObj.display();
//     return 0;
// }

//==================================================================

//Using two ArgClass in class

class ArgClass
{
    public:
        int a;
        void display()
        {
            cout << a <<endl;
        }
};

class MyObjectSingle
{
    private:
        ArgClass *ac1;
        ArgClass *ac2;
    public:
        MyObjectSingle(ArgClass* argAc1, ArgClass* argAc2)
        {
            ac1 = argAc1;
            ac2 = argAc2;
        }
        void display()
        {
            ac1->display();
            ac2->display();
        }
};

int main(void)
{
    ArgClass ac1;
    ac1.a = 10;
    ac1.display();

    ArgClass ac2;
    ac2.a = 20;
    ac2.display();

    MyObjectSingle myObj(&ac1, &ac2);
    myObj.display();

    myObj = {&ac2, &ac1};
    myObj.display();
    return 0;
}

//==================================================================