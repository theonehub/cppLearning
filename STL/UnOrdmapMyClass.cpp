#include <iostream>
#include <unordered_map>

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

        bool operator==(const MyInt& toBeInserted) const {
            return this->a == toBeInserted.getA();
        }
};


struct MyHash {
    size_t operator()(const MyInt& toBeInserted) const {
        cout << toBeInserted.getA() << std::endl;
        return hash<int>()(toBeInserted.getA());// << std::endl;
        //return (toBeInserted.getA());
    }
};

int main(void) {
    unordered_map<MyInt, int, MyHash> myUMap;

    myUMap.insert({1,10});
    pair<unordered_map<MyInt,int, MyHash>::iterator,bool> retVal = myUMap.insert({2,20});

    if (retVal.second) {
        cout <<"inserted";
    }
}