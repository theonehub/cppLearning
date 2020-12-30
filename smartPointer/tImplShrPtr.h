#include <iostream>

using namespace std;

template <class T>
class shrPtr {
    private:
        T* ptr;
        int refCount;
    public:
        shrPtr(T *ptrArg);

        ~shrPtr();

        shrPtr(shrPtr<T> &shrPtrArg);

        T* operator->();
        T& operator*();

};