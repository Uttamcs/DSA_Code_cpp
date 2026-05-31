// Balanced Parenthesis


#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "((()))";
    stack<char> s;
    if(str.length()%2!=0)
    {
        cout<<"Not Balanced";
        return 0;
    }
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else if(str[i]==')')
        {
            if(s.top()=='(')
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Not Balanced";
    }
return 0;
}