/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Creation of stack
    stack<int>st;

    // push operation in stack
    st.push(5);
    st.push(45);
    st.push(51);
    st.push(56);

    // pop operation in stack
    st.pop();

    cout<<"Printing top element of stack "<<st.top()<<endl;

    // empty() returns true if stack is empty and false if stack is non- empty
    if (st.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    
    cout<<"Printing size of stack "<<st.size()<<endl;
    return 0;
}
*/








/*
#include<iostream>
using namespace std;
class Stack
{
    public:
        int *arr;
        int top;
        int size;

    Stack(int size){
        this -> size = size;
        top = -1;
        arr = new int[size];
    }
    void push(int element)
    {
        if(size - top > 1)
        {
            top ++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack Overflow"<<endl; 
        }
    }
    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    Stack s(5);

    s.push(22);
    s.push(72);
    s.push(24);
    s.push(252);
    s.push(02);

    cout<<"Printing top element of the stack "<<s.peek()<<endl;
    s.pop();
    cout<<"Printing top element of the stack "<<s.peek()<<endl;
    if(s.isEmpty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}
*/















/*
//                      Two Stacks

// Design a data structure, which represents two stacks using only one array common for
// both stacks. The data structure should support the following operations
#include<bits/stdc++.h>
using namespace std;
class TwoStack {
    int size;
    int top1;
    int top2;
    int *arr;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 <size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

*/
