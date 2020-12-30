//Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole
// string(not individual words), the input
// string becomes
// much.very.program.this.like.i

#include <iostream>
#include <vector>

using namespace std;


void echoStr(string& mStr)
{
    cout << mStr <<endl;
}

void rearrange(string& mStr)
{
    vector<string> vec;
            
    string temp = "";
    for (int i = 0; i < mStr.length(); i++)
    {
        if (mStr[i] == '.')
        {
            vec.push_back(temp);
            temp = "";
        }
        else
        {
            temp +=mStr[i];
        }
    }

    if (temp != "")
    {
        vec.push_back(temp);
    }
    
    mStr = "";
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        mStr += vec[i] + (i !=0?".":"");
    }
    cout << mStr <<endl;
}


int main(void)
{
    string mStr = "i.like.this.program.very.much";
    echoStr(mStr);
    rearrange(mStr);
}