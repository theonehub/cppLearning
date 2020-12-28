#include <iostream>

using namespace std;

int rearrange(int arr[], int arrlen)
{
    int nIdx = 0;
    int pIdx = 0;
    bool trvsngNv = true;

    while (nIdx < arrlen && pIdx < arrlen)
    {
        if (trvsngNv)
        {
            if (arr[nIdx] < 0)
            {
                nIdx++;
                pIdx++;
            }
            else
            {
                trvsngNv = false;
            }
        }      
        if (!trvsngNv)
        {
            //positive encountored
            if (arr[pIdx] >= 0)
            {
                pIdx++;
            }
            else
            {
                swap(arr[nIdx], arr[pIdx]);
                nIdx++;
                pIdx++;
            }
        }
    }
}

int main(void)
{
    int arr[] = {-10, 12, -45, 3, -7, 11, 12, -30};
    int arrlen = sizeof(arr)/sizeof(arr[0]);

    rearrange(arr, arrlen);
    for (int idx = 0; idx < arrlen; idx++)
    {
        cout << arr[idx] << ", ";
    }
    cout << endl;
}