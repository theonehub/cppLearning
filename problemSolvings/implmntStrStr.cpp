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
    bool isMatchInProgress = false;

    while (jdx < mStr.length())
    {
        if (mStr[jdx] == nStr[idx])
        {
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
            continue;
        }
        jdx++;
    }
    return -1;
}

int main()
{
    string mStr = "Main String to find for SSSubString";
    string nStr = "Sub";
    cout << findStr(mStr, nStr) << endl; 
}