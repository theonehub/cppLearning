#include <iostream>
#include <vector>

/*
Median of two sorted arrays of variable size
*/
using namespace std;

int main(void)
{
    int arr1[] = {1, 3};
    int arr2[] = {2, 4};
    vector<int> finalArr;

    int arr1Len = (sizeof(arr1)/sizeof(arr1[0]));
    int arr2Len = (sizeof(arr2)/sizeof(arr2[0]));
    
    cout << "arr1Len : " << arr1Len << " arr2Len : " << arr2Len << endl;
    int idx = 0, jdx = 0;
    while (idx < arr1Len && jdx < arr2Len)
    {
        if (arr1[idx] < arr2[jdx])
        {
            finalArr.push_back(arr1[idx++]);
        }
        else if (arr1[idx] > arr2[jdx])
        {
            finalArr.push_back(arr2[jdx++]);
        }
        else
        {
            finalArr.push_back(arr1[idx++]);
            finalArr.push_back(arr2[jdx++]);
        }
        
    }

    while(idx < arr1Len)
    {
        finalArr.push_back(arr1[idx++]);
    }

    while(jdx < arr2Len)
    {
        finalArr.push_back(arr2[jdx++]);
    }
 
    for(int i = 0; i < finalArr.size(); i++)
    {
        cout << finalArr[i] << ", ";
    }
    cout << endl;

    int m1 = finalArr.size()/2;
    cout << "m1 : " << m1;
    double median = 0.0;
    if (!(finalArr.size()%2))
    {
        median = (finalArr[m1]+finalArr[m1+1])/2;
    }
    else
    {
        median = finalArr[m1];
    }
    cout << "median : " <<median <<endl;
}