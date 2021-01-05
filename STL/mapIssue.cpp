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

int main(void)
{
    map<int, int> emptyMap;

    map<int, Element> classMap;

    classMap.insert({1, 10});
}

/* 
Output 

implicitCtor()
defaultDtor() : 10
defaultDtor() : 10

*/