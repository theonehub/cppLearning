    // C++ program to illustrate
    // map::insert({key, element})
#include <iostream>
#include <map>
using namespace std;

class Element {
    public:
        int id;
        Element() {
            cout << "defaultCtor()" <<endl;
        }
        Element(int idx) {
            cout << "implicitCtor()" << endl;
            id = idx;
        }
        ~Element() {
            cout << "defaultDtor() : " << id << endl;
        }

};

int main()
{

    // initialize container
    map<int, int> mp;

    // insert elements in random order
    mp.insert({ 2, 20 });
    mp.insert({ 1, 10 });
    mp.insert({ 3, 30 });


    mp.insert({ 5, 50 });
    // prints the elements
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';
    }


    //No duplicate key entry will be inserted
    pair<map<int, int>::iterator, bool> isInserted = mp.insert({3,60});

    if (isInserted.second)
    {
        cout << "Value inserted Key: "<<isInserted.first->first 
            << " Value: "<<isInserted.first->second <<endl;
    }
    else
    {
        cout << "Value Not inserted Key: "<<isInserted.first->first 
            << " Value: "<<isInserted.first->second <<endl;
    }
    

    //Force fully inserted
    mp[3] = 70;

    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';
    }


//Find
    map<int, int>::iterator foundAt = mp.find(7);

    if (foundAt != mp.end())
    {
        cout << "Already present." <<endl;
    }
    else
    {
        cout << "Not found lets insert" <<endl;
        mp.insert(foundAt, {7,70});
    }


    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';
    }

    map<int, int>copyMap;

    copyMap.insert(mp.find(3),mp.find(7));

    for (map<int,int>::iterator itr = copyMap.begin(); itr != copyMap.end(); itr++)
    {
        cout << itr->first<< '\t' << itr->second << '\n';
    }


    map<int, int> emptyMap;

    if (emptyMap.begin() == emptyMap.end())
    {
        cout << "Map is empty!!!" <<endl;
    }

    map<int, Element> classMap;

    Element e = 10;
    classMap.insert({1, 10});


    return 0;
}
