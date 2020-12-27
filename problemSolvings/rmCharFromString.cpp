#include <iostream>

using namespace std;

int prepareSub(string& mStr, char x)
{
    if (mStr.empty())
    {
        cout << "Empty String passed" << std::endl;
        return -1;
    }
    int idx = 0;
    int jdx = 0;
    while(idx < mStr.length())
    {
        if (mStr[idx] == x)
        {
            if (jdx < idx)
            {
                jdx = idx + 1;
            }
            while(jdx < mStr.length() && mStr[jdx] == x)
            {
                jdx++;
            }
            if(jdx == mStr.length())
            {
                return (idx -1);
            }
            mStr[idx] = mStr[jdx];
            mStr[jdx++]= x;
        }
        idx++;
    }
    return (idx-1);
}

int main(void)
{
    string mStr = "this is the main string for this program.";
    int retVal = prepareSub(mStr, 't');
    for (int idx = 0; idx <= retVal; idx++)
    {
        cout << mStr[idx];
    }
    cout << endl;
}