#include <memory>

#include "inc/tBaseClass.h"
#include "inc/tPubDrivedClass.h"
#include "tUnique.h"

//std::unique_ptr<BaseClass> uBc(new BaseClass);
    
    
/**
 * Tips________________________________________________________________________
 * Tips| unique_ptr:                                                          |
 * Tips| BaseClass *tempPtr = new BaseClass()                                 |
 * Tips| std::unique_ptr<BaseClass> cBC = tempPtr;                            |
 * Tips| This is not possible typeConversion is not allowed.                  |
 * Tips| -------------------------------------------------------------------- |
 * Tips| std::unique_ptr<BaseClass> uBcCopy = uBc;                            |
 * Tips| Operator= is deleted in unique_ptr, so this is not allowed.          |
 * Tips|______________________________________________________________________|
 **/



int UniqueC::demoUniquePtr()
{
    //std::unique_ptr<BaseClass> pUBc = std::make_unique<BaseClass>(BaseClass(10)); //with -std=c++14

    //std::unique_ptr<BaseClass> pUBc(new PubDrivedClass());

    std::unique_ptr<BaseClass> pUBc(new BaseClass(10));
    pUBc->Debug();
    pUBc->vFn();

    //std::unique_ptr<BaseClass> pUBcCopy = pUBc; // error: call to implicitly-deleted copy constructor of 'std::unique_ptr<BaseClass>'

    std::unique_ptr<BaseClass> pUBcCopy = std::move(pUBc);
    pUBcCopy->Debug();
    BaseClass *ptr = pUBc.get();

    printf("ptr : %p\n", ptr);  //0x0

    ptr = pUBcCopy.get();
    printf("ptr : %p\n", ptr); 
    pUBcCopy->Debug();
    pUBcCopy.reset(new BaseClass(30));
    pUBcCopy->Debug();

    std::unique_ptr<BaseClass> pUBcOther(new BaseClass(20));
    pUBcOther->Debug();

    pUBcCopy.swap(pUBcOther);
    pUBcCopy->Debug();
    pUBcOther->Debug();

    //---------
    //pUBcCopy.release();
    //pUBcCopy->Debug();  ////segmentation fault
    //---------

    //pUBc->Debug(); //segmentation fault  ./main.out
    return 0;
}
