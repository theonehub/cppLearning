#include <iostream>
using namespace std;

template <class T>
class Calculator
{
    private:
        T num1, num2;
    public:
        Calculator(T t1, T t2) : num1(t1), num2(t2){};
    
        ~Calculator(){};

        bool add() {
            cout << "Addition : " <<num1 + num2 << endl;
            return true;
        }
};