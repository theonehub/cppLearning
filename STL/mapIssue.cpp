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

        Element(const Element& c)
        {
            cout << "CopyCtor()" << endl;
            this->id = c.id +1;
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

    cout << "emplace" <<endl;

    classMap.emplace(2, 20);

    cout << "mainOut" <<endl;
}

/* 
Output 
implicitCtor()
CopyCtor()
defaultDtor() : 10
mainOut
defaultDtor() : 11

*/