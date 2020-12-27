#include <iostream>
#include <array>

using namespace std;

class BaseC
{
    private:
        int var;
    public:
        BaseC()
        {
            cout << "Base DefaultCtor" << endl;
        }

        BaseC(int val)
        {
            var = val;
            cout << "Base ArgtCtor" << endl;
        }

        BaseC(const BaseC& arg)
        {
            cout << "Base CopyCtor" << endl;
            this->var = arg.var;
        }

        ~BaseC()
        {
            cout << "Base Dtor()" << endl;
        }

        void debug()
        {
            cout << "BaseC " << var <<endl;
        }
        
};

int main(void)
{
    array<BaseC, 30> bArray;

    for (int i; i < bArray.size(); i++)
    {
        bArray[i] = i;
    }

    for (int i = 0; i < bArray.size(); i++)
    {
        bArray[i].debug();
    }
}