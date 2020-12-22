#include <memory>

#include "inc/tBaseClass.h"
#include "tAuto.h"

int AutoC::demoAutoPtr()
{
/**
 * Tips________________________________________________________________________
 * Tips|auto_ptr:(deprecated in C11 removed in C17)                           |
 * Tips| Valid in a scope, invokes destructor once it goes out of scope.      |
 * Tips|                                                                      |
 * Tips|Initialized: [std::auto_ptr<BaseClass> aBc(new BaseClass());]         |
 * Tips|                                                                      |
 * Tips|Used:        [aBc->Debug();] operator-> is used to access BaseClass   |
 * Tips|             memberFunction and variables.                            |
 * Tips|                                                                      |
 * Tips|Pointer&:    [aBc.get();] retruns addess BaseClass Address BaseClass* |
 * Tips|                                                                      |
 * Tips|xfrOwnerShip:[std::auto_ptr<BaseClass> aBc2 = aBc;] operator= moves   |
 * Tips|             BaseClass pointer to aBc2 auto_ptr and set aBC to NULL.  |
 * Tips|                                                                      |
 * Tips|reset:       [aBc2.reset()] invokes Destructor(), may lead to segFault|
 * Tips|             if get() is used and pointer is preseved and used.       |
 * Tips|                                                                      |
 * Tips|release:     [aBc2.release()] don't invokes Destructor, may lead to   |
 * Tips|             memleak.                                                 |
 * Tips|______________________________________________________________________|
 **/

    BaseClass *pCopy = NULL;
    {
        std::auto_ptr<BaseClass> aBc(new BaseClass());
        std::cout << "BaseClass Address [aBC] : " << aBc.get() << ", Should be Valid\n";
        aBc->Debug();

        std::auto_ptr<BaseClass> aBc2 = aBc;
        std::cout << "BaseClass Address [aBc2] : " << aBc2.get() << ", Should be same as above\n";
        std::cout << "BaseClass Address [aBc] : " << aBc.get() << ", Should be NULL\n";

        aBc2->Debug();

        //aBc->Debug();  //will lead to segFault

        pCopy = aBc2.get();
        std::cout << "BaseClass Address [pCopy] : " << pCopy << ", Should be same as aBc2\n";
        std::cout << "BaseClass Address [aBc2] : " << aBc2.get() << ", Should be same as above\n";
        pCopy->Debug();

        aBc2.release(); //invokes destructor, reset pointer to NULL.
        std::cout << "BaseClass Address [aBc2] : " << aBc2.get() << ", Should be NULL after reset\n";

        aBc2.reset(); //don't invokes destructor, reset pointer to NULL.
        std::cout << "BaseClass Address [aBc2] : " << aBc2.get() << ", Should be NULL after reset\n";
    } //auto_ptr invokes Destructor()

    //pCopy->Debug();  //will lead to segFault incase of release 
    //delete pCopy;
    return 0;
}
