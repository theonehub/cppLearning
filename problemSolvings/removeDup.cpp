#include <iostream>

using namespace std;

void echoStr(string& mStr)
{
    cout << mStr <<endl;
}

void removeDup(string& mStr)
{
    int counter = 0, x = 0;
    int length = 0;

    for (int jdx = 0; jdx < mStr.length(); jdx++)
    {
        x = mStr[jdx] - 'a';
        if ((counter & (1 << x)) == 0) {
            mStr[length++] = mStr[jdx];
            counter |= (1 << x);
        }
    }
    cout << "length " << length << endl;
    mStr = mStr.substr(0, length);
}


int main(void)
{
    string mStr = "Ankitiscodingwithusernametheonehub";
    removeDup(mStr);
    echoStr(mStr);
}