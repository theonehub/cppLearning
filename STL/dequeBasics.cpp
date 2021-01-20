#include <iostream>
#include <deque>
using namespace std;


//LIFO ---> push_front() -- pop_front()
//FIFO ---> push_front() -- pop_back()

void printMe(deque<int> &obj)
{
    // for (deque<int>::iterator it = obj.begin(); it != obj.end(); it++)
    // {
    //     cout << *it <<", ";
    // }

    cout << obj.size()<<endl;
    while (!obj.empty())
    {
        cout << obj.front() << ", ";
        obj.pop_front();
    }
}
int main(void)
{
    deque<int> obj;

    for (int i : {1,2,6,7,3,9,10})
    {
        cout << i <<",";
        obj.push_front(i);
        
    }
cout << endl;
    printMe(obj);
}