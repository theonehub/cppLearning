#include <iostream>
#include <map>

using namespace std;

class MyInt {
    private:
        int a;
    public:

        MyInt() { 
            cout << "MyInt()" << endl;
        }
        MyInt(int val) {
            cout << "MyInt " << val <<endl;
            a = val;
        }
        int getA() const { 
            //cout << "GetA : " <<a<<endl;
            return a;
        }
        void setA(int val) { a = val;}

        bool operator<(const MyInt& right) const{
            return this->a < right.a;
        }
};

struct cmp {
    bool operator()(const MyInt& toBeInserted, const MyInt& present) const {
        //return left.getA() < right.getA();
        cout << "present: " << present.getA() <<" toBeInserted: "<<toBeInserted.getA()<< std::endl;
        return present < toBeInserted;
    }
};

int main(void) {
    map<MyInt, int, cmp> myMap;

    myMap.insert({1,10});
    pair<map<MyInt,int>::iterator,bool> retVal = myMap.insert({2,20});

    if (retVal.second) {
        cout <<"inserted";
    }
}