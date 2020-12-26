#include <iostream>
#include <pthread.h>
#include <vector>
#include <stdlib.h>
#include "ThrData.h"

using namespace std;

#define LOOP_NUM 500000000
long long sum = 0;

pthread_mutex_t countLock;

void* counting(void *arg)
{
    ThrData *tData = (ThrData*)arg;

    cout << "ThreadId : " << tData->m_ThreadIndex
         << " : " << tData->m_ThreadOffSet << endl;

    for (int i = 0; i < LOOP_NUM; i++)
    {
        pthread_mutex_lock(&countLock);
        sum += tData->m_ThreadOffSet;
        pthread_mutex_unlock(&countLock);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    vector<ThrData> threadRef;

    if (argc < 2) 
    {
        cout << "Less Arguements " << argc << "!!!!" << endl;
        return -1;
    }
    
    for (int i = 1; i < argc; i++)
    {
        cout << "Args at "<< i << " : "<<argv[i] << std::endl;

        int offset = atoi(argv[i]);
        ThrData tData(i, offset);

        threadRef.push_back(tData);
    }
    
    pthread_mutex_init (&countLock, NULL);

    for (int i = 0; i < threadRef.size(); i++)
    {
        pthread_t tId;
        ThrData &tdata = threadRef[i];
        pthread_create(&tId, NULL, counting, &tdata);
        tdata.m_ThreadId = tId;
    }

    for (int i = 0; i < threadRef.size(); i++)
    {
        threadRef[i].Debug();
    }

    for (int i = 0; i < threadRef.size(); i++)
    {
        pthread_join(threadRef[i].m_ThreadId, NULL);
    }
    
    printf("Sum: %lld\n",sum);
    return 0;
}