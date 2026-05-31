// Implement min stack

/*
// Approach - 1
#include <bits/stdc++.h>
using namespace std;
class MinStack {
    public:
    stack<pair<int,int>> s; 
    MinStack() {
        
}
void push(int val) {
    if(s.empty()){
            s.push({val,val});
        }
        else{
            s.push({val,min(val,s.top().second)});
        }
    }
    void pop() {
        s.pop();
    }
    int top() {
        return s.top().first;
    }
    int getMin() {
        return s.top().second;
    }
};
int main()
{
    MinStack *obj = new MinStack();
    obj->push(5);
    obj->push(54);
    obj->push(15);
    obj->push(25);
    obj->push(55);
    
    cout << obj->getMin() << endl;
    cout<< obj -> top() << endl;
    obj -> pop();
    cout << obj -> getMin() << endl;
    cout<< obj -> top() << endl;
    obj -> pop();
    
    return 0;
}
*/







// Approach - 2

#include <bits/stdc++.h>
using namespace std;
int main()
{
    
return 0;
}