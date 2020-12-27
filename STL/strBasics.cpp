#include <iostream>
#include <string>
using namespace std;

//Demonstrate Basic String functions
void dumpString(string& argString)
{
    printf("------------------------------------\n");
    printf("Sizeof Object : %lu\n", sizeof(argString));
    printf("Content: %s\n", argString.c_str());

    if (argString.empty())
    {
        printf("String is Empty!!!\n");
    }

    printf("String length %lu\n", argString.length());
    printf("String size %lu\n", argString.size());
    printf("String capacity %lu\n",argString.capacity());
    printf("String MaxSize %lu\n", argString.max_size());
    // argString.resize(argString.capacity()*2);
    // printf("String capacity %lu\n",argString.capacity());
    // printf("String length %lu\n", argString.length());
    printf("------------------------------------\n");
}

void strErase(string& argString)
{
    //argString.erase(10,8); //Starting with 10th index when first index is 0th. // 1234567890[22345678]90323456789042345678905234567890

    //argString.erase(10,90); //Delete till end of the string. // 1234567890[2234567890323456789042345678905234567890]
    //argString.erase(90,92); //terminating with uncaught exception of type std::out_of_range: basic_string


    argString.erase(argString.begin()+10, argString.begin()+18); // 1234567890[22345678]90323456789042345678905234567890
    dumpString(argString);
}

void strAppend(string& baseStr, string& manipulatorStr, const char *arr)
{
    //baseStr.append(manipulatorStr);
    //baseStr.append(manipulatorStr, 10, 8);
    //baseStr.append(arr);
    //baseStr.append(arr,8);
    //baseStr.append(8,'#');
    baseStr.append(manipulatorStr.begin()+10,manipulatorStr.begin()+18);


    dumpString(baseStr);
}


void strAssign(string& baseStr, string& manipulatorStr, const char *arr)
{
    //baseStr.assign(manipulatorStr);
    //baseStr.assign(manipulatorStr, 10, 8);
    //baseStr.assign(arr);
    //baseStr.assign(arr,8);
    //baseStr.assign(8,'#');
    baseStr.assign(manipulatorStr.begin()+10,manipulatorStr.begin()+18);
    

    dumpString(baseStr);
}

void strCompare(string& baseStr, string& manipulatorStr, const char *arr)
{
    int retVal = baseStr.compare(manipulatorStr);
    if (0 == retVal)
    {
        printf("Equal\n");
    } 
    else if (0 > retVal)
    {
        printf("Either the value of the first character that does not match is lower in the compared string, or all compared characters match but the compared string is shorter.\n");
    }
    else
    {
        printf("Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.\n");
    }
}

void strFind(string& baseStr)
{
    //int position = baseStr.find("789");
    //int position = baseStr.find("789", 10);
    int position = baseStr.find("7");
    if (position != std::string::npos)
    {
        printf("789 found at %d\n", position);
    }
    else
    {
        printf("NotFound!!!");
    }

    //find_first_not_of
    string statement ("look for non-alphabetic characters...");
    size_t found = statement.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
    if (found!= string::npos)
    {
        printf("Char found is : %c\n",statement[found]);
    }

    found = statement.find_first_of("aeiou");
    while(found != string::npos)
    {
        statement[found] = '*';
        found = statement.find_first_of("aeiou");
    }
    printf("Statement : %s\n",statement.data());
}




int main()
{
    //Ctor()
    const char arr[] = {"12345678902234567890323456789042345678905234567890"};
    string emptyString;
    string str50(arr);
    string str50Copy(str50);
    string str50SubSet(str50, 10, 8);
    string str20FromArr(arr, 20);
    string str10Filled(10, '#');
    string str10FilledByAscii(10, 42);
    string str50SubSetByItr(str50.begin()+10,str50.begin()+18);
    string str10InitializerList{'1','2','3','4','5','6','7','8','9','0'};

    dumpString(emptyString);
    dumpString(str50);
    strErase(str50);
    dumpString(str50Copy);
    dumpString(str50SubSet);
    dumpString(str20FromArr);
    dumpString(str10Filled);
    dumpString(str10FilledByAscii);
    dumpString(str50SubSetByItr);
    dumpString(str10InitializerList);

    strAppend(str20FromArr, str50Copy, arr);
    strCompare(str20FromArr, str50Copy, arr);
    strFind(str20FromArr);

    str20FromArr.front() = 'A';
    printf("Str20 : %s\n", str20FromArr.data());
}