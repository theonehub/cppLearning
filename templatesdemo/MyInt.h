#include <iostream>
using namespace std;

class MyInt 
{
    private:
        int item;

    public:
        MyInt(int a):item(a){};

        int operator+(MyInt& a) {
            return this->item + a.item;
        }
};