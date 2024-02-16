/*
// Reverse a string using stack
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Uttam";
    string ans="";
    stack <char> ch;
    for (int i = 0; i < s.size(); i++)
    {
        ch.push(s[i]);
    }
    while (!ch.empty())
    {
        ans.push_back(ch.top());
        ch.pop();
    }
    cout<<"After reversing string is "<<ans<<endl;
    return 0;
}
*/

/*
// Valid parenthesis
#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    stack<char>chr;
    for(int i= 0; i<expression.length(); i++)
    {
        char ch = expression[i];
        if(ch == '(' || ch == '{' ||ch == '[')
        {
            chr.push(ch);
        }
        else
        {
            if(chr.empty())
            {
                return false;
            }
            char top = chr.top();
            chr.pop();
            if(ch == ')' && top != '(' || ch == '}' && top != '{' || ch == ']' && top != '[')
            {
                return false;
            }
        }
    }
    return chr.empty();
}
int main()
{
    cout<<isValidParenthesis("{([)]}")<<endl;
    return 0;
}
*/

/*
// Insert An Element At Its Bottom In A Given Stack

#include<bits/stdc++.h>
using namespace std;
stack<int> pushAtBottom(stack<int>& myStack, int x)
{
    // base case
    if(myStack.empty())
    {
        myStack.push(x);
        return myStack;
    }
    int num = myStack.top();
    myStack.pop();

    // Recursive call
    pushAtBottom(myStack, x);

    myStack.push(num);

    return myStack;
}
int main()
{
    stack<int> st;
    st.push(4);
    st.push(42);
    st.push(34);
    st.push(49);
    st.push(15);
    pushAtBottom(st, 5);
    return 0;
}
*/

/*
// Reverse Stack Using Recursion
#include<bits/stdc++.h>
using namespace std;
void pushAtBottom(stack<int>& myStack, int x)
{
    // base case
    if(myStack.empty())
    {
        myStack.push(x);
        return ;
    }
    int num = myStack.top();
    myStack.pop();

    // Recursive call
    pushAtBottom(myStack, x);

    myStack.push(num);

}
void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty())
    {
        return ;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    pushAtBottom(stack , num);
}
int main()
{
    stack<int> st;
    st.push(4);
    st.push(42);
    st.push(34);
    st.push(49);
    st.push(15);
    reverseStack(st);
    return 0;
}
*/

/*
// Redundant Brackets

#include <bits/stdc++.h>
using namespace std;
bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i= 0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch== '*' || ch =='/')
        {
            st.push(ch);
        }
        else
        {
            // ya tohh character ho ya lowercase alphabets
            if(ch == ')')
            {
                bool isRedundant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                      isRedundant = false;
                    }
                    st.pop();
                }
                if( isRedundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "(a+(b*(a/c)))";
    cout<<str<<endl;
    cout<<findRedundantBrackets(str)<<endl;
    return 0;
}
*/












/*
// Minimum cost to make the string valid

#include <bits/stdc++.h>
using namespace std;
int findMinimumCost(string str)
{
    stack<char> st;
    if (str.length() % 2 == 0)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if((!st.empty()) && (st.top() == '{')) 
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }
    }
    else
    {
        return -1;
    }
    int a=0, b=0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    return ((a+1)/2) + ((b+1)/2);
}
int main()
{
    cout << findMinimumCost("{{{}") << endl;
    return 0;
}

*/
