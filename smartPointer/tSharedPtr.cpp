#include <memory>

#include "inc/tBaseClass.h"
#include "inc/tPubDrivedClass.h"
#include "tSharedPtr.h"

//std::unique_ptr<BaseClass> uBc(new BaseClass);


int SharedC::demoSharedPtr()
{
    //BaseClass* pBc = new BaseClass(10);
    //std::shared_ptr<BaseClass> pSBc(pBc);
    //std::shared_ptr<BaseClass> pSBc(new BaseClass(10));
    std::shared_ptr<BaseClass> pSBc = std::make_shared<BaseClass>(10);
    pSBc->Debug();
    pSBc->vFn();
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;

    std::shared_ptr<BaseClass> pSBcCopy = pSBc;
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;

    std::weak_ptr<BaseClass> pSBcWCopy = pSBc;
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;

    std::shared_ptr<BaseClass> pSBcRef = pSBcWCopy.lock();
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;
    
    pSBcRef.reset();
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;

    pSBcRef = pSBcWCopy.lock();
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;

    pSBc->Debug();


    std::shared_ptr<BaseClass> pSBcNew = std::make_shared<BaseClass>(20);

    std::cout << "RefCount : " << pSBc.use_count() << std::endl;
    pSBcNew.swap(pSBc);
    std::cout << "RefCount : " << pSBc.use_count() << std::endl;
    pSBc->Debug();

    pSBcNew->Debug();

    pSBcRef->Debug();

    return 0;
}
