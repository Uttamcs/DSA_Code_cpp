#include<bits/stdc++.h>
using namespace std;
void solve(string digits, int index, string output, vector<string> &ans, string mapping)
{
    // base case
    if (index>= digits.length())
    {
        ans.push_back(output);
        return ;
    }
    int number=digits[index]-'0';
    string value= mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, index+1, output, ans, mapping);
        output.pop_back();
    }
    
    
}
vector <string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length()==0)
    {
        return ans;
    }
    
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output="";
    int index=0;
    solve(digits, index, output, ans, mapping);
    return ans;
}
int main()
{
    string digits="27";
    // letterCombinations(digits);
    return 0;
}