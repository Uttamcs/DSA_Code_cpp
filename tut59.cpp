#include <bits/stdc++.h>
using namespace std;
class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        // for first data
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                int val = (2 * data) - mini;
                s.push(val);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }
    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        int curr = s.top();
        s.pop();
        
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }
    int top()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int getMin()
    {
        if (s.empty())
            return -1;
        return mini;
    }
};
int main()
{
    SpecialStack s1;
    s1.push(5);
    cout << s1.top() << endl;
    cout << s1.getMin() << endl;
    s1.push(8);
    cout << s1.top() << endl;
    cout << s1.getMin() << endl;
    cout << "After pushing 1" << endl;
    s1.push(1);
    cout << s1.top() << endl;
    cout << s1.getMin() << endl;
    return 0;
}