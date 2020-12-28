//Double the first element and move zero to end
//For a given array of n integers and assume that ‘0’ as an invalid number 
//and all other as a valid number. Convert the array in such a way that if 
//both current and next element is valid then double current value and replace 
//the next number with 0. After the modification, rearrange the array such that 
//all 0’s shifted to the end. 

// Input : arr[] = {2, 2, 0, 4, 0, 8}
// Output : 4 4 8 0 0 0

// Input : arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
// Output :  4 2 12 8 0 0 0 0 0 0

#include <iostream>

using namespace std;

int fromatArr(int arr[], int arrlen)
{
    //int arrlen = sizeof(arr[])/sizeof(arr[0]);
    int noOfMov = 0;
    int idx = 0;
    while ( idx < (arrlen-1-noOfMov))
    {
        cout << arr[idx] << ", ";

        if (arr[idx] == 0)
        {
            int jdx = idx+1;
            int kdx = idx;
            while(jdx < (arrlen-(1+noOfMov)))
            {
                
                arr[kdx++] = arr[jdx++];
            }
            arr[jdx-1] = 0;
            continue;
        }
        else if (arr[idx] != 0 && arr[idx+1] != 0)
        {
            arr[idx] *= 2;
            arr[idx+1] = 0;
        }
        idx++;
    }
    
    return (idx-1);
}

int main(void)
{
    int arr[] = {2, 2, 0, 4, 0, 8};
    int arrLen = (sizeof(arr)/sizeof(arr[0]));
    int pos = fromatArr(arr, arrLen);
    for (int idx = 0; idx < (sizeof(arr)/sizeof(arr[0])); idx++)
    {
        cout << arr[idx];
    }
    cout << endl;
}