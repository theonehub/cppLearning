#include <iostream>
#include <vector>
#include <unistd.h>

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
    vector<BaseC*> vec;
    vec.reserve(16);

    BaseC a(1);
    BaseC b(2);
    BaseC c(3);
    BaseC d(4);
    BaseC e(5);
    BaseC f(6);
    BaseC g(7);
    BaseC h(8);
    sleep (10);
    vec.push_back(&a);
    sleep(3);
    vec.push_back(&b);
    sleep(3);
    vec.push_back(&c);
    sleep(3);
    vec.push_back(&d);
    sleep(3);
    vec.push_back(&e);
    sleep(3);
    vec.push_back(&f);
    sleep(3);
    vec.push_back(&g);
    sleep(3);
    vec.push_back(&h);
    sleep(3);
    vector<BaseC> vecCopy;
    vecCopy.reserve(8);
    printf("Sizeof %lu\n", vecCopy.size());
    vecCopy.push_back(a);
    vecCopy.push_back(b);
    printf("Sizeof %lu\n", vecCopy.size());
    vecCopy.erase(vecCopy.begin());
    printf("Sizeof %lu\n", vecCopy.size());

    //vec.emplace_back(10);

//     vector<BaseC> first;
//     vector<BaseC> second;

// //Assign
//     first.assign(10, a); //assign a to 10 elements.

//     //vector<BaseC>::iterator it = first.begin();
//     auto it = first.begin();
//     second.assign (++it, first.end()-1);

// //Back
//     BaseC& refBC = vec.back();
//     refBC.debug();

// //cbegin
//     vector<BaseC>::iterator it = vec.cbegin();

}