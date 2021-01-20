#ifndef __TBASECLASS__
#define __TBASECLASS__

#include <iostream>

class BaseClass
{
    private:
    int baseVariable;


    public:
    BaseClass();
    BaseClass(int);
    BaseClass(int&);

    virtual ~BaseClass();

    void SetBaseBaseVariable(int&);
    void SetBaseBaseVariable(int);
    int GetBaseVariable();
    void Debug();
    virtual void vFn();
};

#endif
