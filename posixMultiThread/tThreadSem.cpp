#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <vector>
#include <unistd.h>
using namespace std;

sem_t semZero;
sem_t semOne;

void* writeZero(void* args)
{
    int count = 10;
    while(count--)
    {
        cout << "0"<< std::endl;
        sem_post(&semOne);
        sem_wait(&semZero);
    }
    return NULL;
}

void* writeOne(void* args)
{
    int count = 10;
    while(count--)
    {
        sem_wait(&semOne);
        cout << "1"<< std::endl;
        sem_post(&semZero);
    }
    return NULL;
}

int main(void) {
    pthread_t tZero;
    pthread_t tOne;

    sem_init(&semZero, 0, 0);
    sem_init(&semOne, 0, 0);

    pthread_create(&tZero, NULL, writeZero, NULL);
    pthread_create(&tOne, NULL, writeOne, NULL);

    pthread_join(tZero,NULL);
    pthread_join(tOne,NULL);
}