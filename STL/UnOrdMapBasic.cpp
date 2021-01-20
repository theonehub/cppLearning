#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    unordered_map<int, int> uMap;

    uMap.insert({1,10});
    auto it = uMap.insert({1,20});
    if (it.second) {cout << "inserted"<<endl;}
    return 0;
}