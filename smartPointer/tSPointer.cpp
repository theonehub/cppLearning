#include <iostream>
#include <memory>

#include "inc/tBaseClass.h"
#include "tAuto.h"
#include "tUnique.h"
#include "tImplShrPtr.h"
#include "tSharedPtr.h"
/**
 * Tips_______________________________________________________________________
 * Tips| Smart Pointers: Takes care of deleting pointers once they are no     | 
 * Tips| longer required.It will decided based on the type of pointer when to | 
 * Tips| delete, but user don't have to think worry about deleting pointer.   |
 * Tips|                                                                      |
 * Tips| [std::unique_ptr<BaseClass> uBc = std::make_XXXXXX<BaseClass>();]    |
 * Tips|                                                                      |
 * Tips| [std::unique_ptr<BaseClass> uBc(new BaseClass);]                     |
 * Tips|                                                                      |
 * Tips| Above are the two ways of defining smart pointer but One shall use   |
 * Tips| make_XXXXXX to define it as in case of new one there is a porblem    |
 * Tips| incase of using new, lets assume if there happens an issue while     |
 * Tips|              [std::unique_ptr<BaseClass> uBc]                        |
 * Tips|                       where as                                       |
 * Tips|                   [(new BaseClass)]                                  |
 * Tips| is already executed and here we are leaving a memory leak.           |
 * Tips|                                                                      |
 * Tips| #include <memory>                                                    |
 * Tips| auto_ptr:                                                            |
 * Tips|  Scope Based pointer Manager.                                        |
 * Tips|                                                                      |
 * Tips| unique_ptr:                                                          |
 * Tips|  1. Can not be copied to another pointer.                            |
 * Tips|  2. Its valid in scope.                                              |
 * Tips|  3. make_unique<BaseClass>();                                        |
 * Tips|                                                                      |
 * Tips| shared_ptr:                                                          |
 * Tips|  1. make_shared<BaseClass>() is the correct way to do it as shared   |
 * Tips|     pointer, allocat memory for book keeping and using new for Base  |
 * Tips|     Class is going to be two allocations. So better to use           |
 * Tips|              [std::make_shared<BaseClass>();]                        |
 * Tips|                                                                      |
 * Tips|                                                                      |
 * Tips|______________________________________________________________________|
 **/ 


int main(void)
{
   // std::cout << "Invoking demoAuto" << std::endl;
   // AutoC sAuto;
   // sAuto.demoAutoPtr();
   // std::cout << "Done with demoAuto" << std::endl;

   // std::cout << "Invoking demoUnique" << std::endl;
   // UniqueC sUnique;
   // sUnique.demoUniquePtr();
   // std::cout << "Done with demoUnique" << std::endl;

   //std::cout << "Invoking demoShare" << std::endl;
   //demoShared();
   //std::cout << "Done with demoShared" << std::endl;
   // shrPtr<BaseClass> sPtr(new BaseClass());
   // sPtr->SetBaseBaseVariable(10);
   // shrPtr<BaseClass> sPtrCopy;
   // sPtrCopy = sPtr;

   SharedC sShared;
   sShared.demoSharedPtr();
}







