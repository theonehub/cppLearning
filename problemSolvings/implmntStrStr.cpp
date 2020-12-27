#include <iostream>

using namespace std;

int findStr(string& mStr, string& nStr)
{
    if (nStr.length() > mStr.length())
    {
        cout<< "error : not found" <<endl;
        return -1;
    }
    
    int idx = 0;
    int jdx = 0;
    int kdx = 0;
    bool isMatchInProgress = false;

    while (jdx < mStr.length())
    {
        if (mStr[jdx] == nStr[idx])
        {
            if (false == isMatchInProgress)
            {
                kdx = jdx;
            }
            idx++;
            isMatchInProgress = true;
            if (idx == nStr.length())
            {
                cout <<"Matched!!!"<< endl;
                return (jdx - (idx - 1));
            }
        }
        else if (true == isMatchInProgress)
        {
            isMatchInProgress = false;
            idx = 0;
            jdx = kdx;
        }
        jdx++;
    }
    return -1;
}

int main()
{
    string mStr = "mississippi";
    //string mStr = "Main String to find for any String";
    string nStr = "issip";
    cout << findStr(mStr, nStr) << endl; 
}