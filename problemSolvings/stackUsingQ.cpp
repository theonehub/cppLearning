#include <iostream>
#include <queue>

using namespace std;

class stack_using_q
{
    private:
        queue<int> *q1, *q2;
        int cElem;

    public:

        stack_using_q()
        {
            q1 = new queue<int>();
            q2 = new queue<int>();
            cElem = 0;
        }

        void push(int data)
        {
            q1->push(data);
            cElem++;
        }

        void pop()
        {
            if(!q1->empty())
            {
                while(q1->size() != 1)
                {
                    q2->push(q1->front());
                    q1->pop();
                }
                queue<int> *q = q1;
                q1 = q2;
                q2 = q;
            }
        }

        int top()
        {
            if (!q1->empty())
            {
                pop();
                int temp = q2->front();
                q2->pop();
                return temp;
            }
            return -1;
        }
};
