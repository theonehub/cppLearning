#ifndef __UNIQUE_PTR__
#define __UNIQUE_PTR__

#include <iostream>

class UniqueC
{
    private:

    public:
    UniqueC()
    {
        std::cout << "UniqueC Ctor()" << std::endl;
    }

    ~UniqueC()
    {
        std::cout << "UniqueC Dtor()" << std::endl;
    }

    int demoUniquePtr();
};

#endif
