#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* worker(void *args) {
    // int local = 10;
    // int *retval = &local;
    int *retval = new int(); 
    int passedId = *(int*)args;
    printf("Worker invoked %d\n", passedId);
    //sleep(10);
    *retval = rand();
    std::cout << "RetVal in Thread : " << *retval << std::endl;
    return retval;
}

int main()
{
    pthread_t tId[10];
    printf("Before Create\n");
    for (int idx = 0; idx < 10; idx++)
    {
        pthread_create(&tId[idx], NULL, worker, &idx);
        printf("Created %d\n", tId[idx]);
        // if (idx%2 == 0)
        // {
        //     int err = pthread_detach(tId[idx]);
        //     if (err)
        //     {
        //         std::cout << "Failed to Detach ThreadId: "<<idx<<std::endl;
        //     }
        // }
    }
    int *retVal;
    for (int i = 0; i < 10; i++)
    {
        
        if (EINVAL != pthread_join(tId[i], (void**) &retVal))
        {
            std::cout << "ThreadId : " << tId[i] << " retval : "<<*retVal << std::endl;
            delete retVal;
        }
    }
     
    printf("After Join\n");
    exit(0);
}

