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
    std::unique_ptr<BaseClass> pUBc = std::make_unique<BaseClass>();
    pUBc->Debug();
    pUBc->vFn();

    std::unique_ptr<BaseClass> pUDc = std::make_unique<PubDrivedClass>();
    pUDc->Debug();
    pUDc->vFn();
    return 0;
}
