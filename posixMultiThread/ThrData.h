#include <iostream>
#include <pthread.h>

using namespace std;

class ThrData
{
public:
    int m_ThreadIndex;
    int m_ThreadOffSet;
    pthread_t m_ThreadId;

    ThrData(int threadIndex, int threadOffSet):m_ThreadIndex(threadIndex),m_ThreadOffSet(threadOffSet){}

    ~ThrData(){};

    void Debug()
    {
        cout <<"|"<< "ThredIndex : " <<m_ThreadIndex <<"|";
        cout << "ThredOffSet : " <<m_ThreadOffSet<<"|";
        cout << "ThredId : " <<m_ThreadId<<"|"<< endl;
    }
};