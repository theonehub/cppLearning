#ifndef __SHARED_PTR__
#define __SHARED_PTR__

#include <iostream>

class SharedC
{
    private:

    public:
    SharedC()
    {
        std::cout << "SharedC Ctor()" << std::endl;
    }

    ~SharedC()
    {
        std::cout << "SharedC Dtor()" << std::endl;
    }

    int demoSharedPtr();
};

#endif
