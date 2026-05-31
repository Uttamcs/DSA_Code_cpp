// // Infix to postfix
// #include <bits/stdc++.h>
// using namespace std;
// int prec(char c)
// {
//     if (c == '^')
//         return 3;
//     else if (c == '*' || c == '/')
//         return 2;
//     else if (c == '+' || c == '-')
//         return 1;
//     else
//         return -1;
// }
// int main()
// {
//     string str = "a+b*c-d";
//     stack<char> s;
//     string ans = "";
//     int i = 0;
//     while(i < str.length()){
//         if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
//         {
//             ans += str[i];
//         }
//         else if (str[i] == '(')
//         {
//             s.push(str[i]);
//         }
//         else if (str[i] == ')')
//         {
//             while (!s.empty() && s.top() != '(')
//             {
//                 ans += s.top();
//                 s.pop();
//             }
//             if (!s.empty())
//             {
//                 s.pop();
//             }
//         }
//         else
//         {
//             while (!s.empty() && prec(str[i]) <= prec(s.top()))
//             {
//                 ans += s.top();
//                 s.pop();
//             }
//             s.push(str[i]);
//         }
//         i++;
//     }
//     cout << ans << endl;
//     return 0;
// }



// Infix to prefix conversipn 

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "a+b*c-d";
    stack<char> s;
    string ans = "";

}