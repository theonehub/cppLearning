#include <iostream>

#include <iostream>
#include <queue>
#include <vector>


struct compareFunc {
    bool operator ()(int& a, int& b)
    {
        return a > b;
    }
};

//void printMe(std::priority_queue<int, std::vector<int>, std::less<int>> &pQ)
void printMe(std::priority_queue<int, std::vector<int>, compareFunc> &pQ)
{
    while(!pQ.empty())
    {
        std::cout << pQ.top() <<std::endl;
        pQ.pop();
    }
}

int main(void)
{
    std::priority_queue<int, std::vector<int>, compareFunc> pQ;

    for (int elem : {10, 4, 100, 5, 9, 32, 2, 32, 30})
    {
        pQ.push(elem);
    }

    printMe(pQ);
}
