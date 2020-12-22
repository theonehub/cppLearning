#ifndef __AUTO_PTR__
#define __AUTO_PTR__

#include <iostream>

class AutoC
{
    private:

    public:
    AutoC()
    {
        std::cout << "AutoC Ctor()" << std::endl;
    }

    ~AutoC()
    {
        std::cout << "AutoC Dtor()" << std::endl;
    }

    int demoAutoPtr();
};

#endif
