#ifndef __PUB_DRIVED_CLASS__
#define __PUB_DRIVED_CLASS__
#include <iostream>
#include "tBaseClass.h"

class PubDrivedClass : public BaseClass
{
    private:
        int drivedVariable;
    public:
        PubDrivedClass();
        ~PubDrivedClass();

        void Debug();
        void vFn();
};


#endif
