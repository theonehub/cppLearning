#include <iostream>
using namespace std;

template <class T>
T Larger(T arg1, T arg2)
{
    return (arg1>arg2) ? arg1:arg2;
}

template <class T>
bool swapLocal(T& arg1, T& arg2)
{
    T tempVar = arg1;
    arg1 = arg2;
    arg2 = tempVar;
    return true;
}

int main(void)
{
    int a = 5, b = 6;
    float c = 10.4, d = 1.5;
    char e = 'a', f = 'd';

    cout << " Larger : " << Larger(a, b) << endl;
    cout << " Larger : " << Larger(c, d) << endl;
    cout << " Larger : " << Larger(e, f) << endl;

    swapLocal(a, b);
    

}