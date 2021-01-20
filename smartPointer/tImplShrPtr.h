#include <iostream>

using namespace std;

template <class T>
class shrPtr {
    private:
        T* ptr;
        int refCount;
    public:
        shrPtr(T *ptrArg)
        {
            this->ptr = ptrArg;
            refCount++;
        }

        shrPtr()
        {
            this->ptr = NULL;
            refCount = 0;
        }

        ~shrPtr()
        {
            refCount--;
            if (refCount == 0)
            {
                delete this->ptr;
            }
        }

        shrPtr(shrPtr<T> &shrPtrArg)
        {
            this->ptr = shrPtrArg.ptr;
            this->refCount = ++shrPtrArg.refCount;
        }

        shrPtr<T>& operator=(shrPtr<T> &shrPtrArg)
        {
            this->ptr = shrPtrArg.ptr;
            this->refCount = ++shrPtrArg.refCount;
        }

        T* operator->()
        {
            return this->ptr;
        }
        T& operator*()
        {
            return *(this->ptr);
        }

};