/*
        //  INPUT OUTPUT OF STRING
#include <bits/stdc++.h>
using namespace std;
int getLength(char name[])
{
    int count=0;
    for (int i = 0; name[i] !='\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    cout << "Enter you name:" << endl;
    cin >> name;
    cout << "Your name is " << name << endl;
    cout << "Your name length is " << getLength(name) << endl;
    return 0;
}
*/

/*
//              REVERSE A STRING
#include <bits/stdc++.h>
using namespace std;
void reverse_str(char str[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(str[s++], str[e--]);
    }
}
int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char str[20];
    cout << "Enter a string:" << endl;
    cin >> str;
    int len = getLength(str);
    reverse_str(str, len);
    cout << "Reversed string is " << str << endl;

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

char toLowercase(char ch){
    if ((ch>='a' && ch<='z')||(ch>='0' && ch<='9')){
        return ch;
    }
    else{
        return char(ch-'A'+'a');
    }
}

bool checkPalindrome(string s)
{
    int start=0;
    int end=s.size()-1;
    while(start<end)
    {
        if(s[start]!=s[end])
        {
            return 0;
        }
        else
        {
            start++;
            end--;
        }
    }
    return 1;
}


bool isPallindrome(string s){
    string temp="";
    for(int i=0; i<s.length(); i++){
        if (valid(s[i])){
            temp.push_back(s[i]);
        }
    }
    for(int j=0; j<temp.length(); j++) {
            temp[j] = toLowercase(temp[j]);
        }
    return checkPalindrome(temp);
}

int main()
{
    string str="codingninjassajNiNgNidoc";
    cout<<isPallindrome(str)<<endl;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
char toLower(char ch){
    if(ch>='A' && ch<='Z')
    {
        return ch=ch-'A'+'a';
    }
    else
    {
        return ch;
    }
}
bool isValid(char ch){
    if ((ch>='a' && ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0' &&ch<='9')){
        return 1;
    }
    else
    {
        return 0;
    }
}
bool checkPallindrome(string st){
    int s=0;
    int e=st.size()-1;
    while(s<e)
    {
        if (st[s]!=st[e]){
            return 0;
        }
        else
        {
        s++;
        e--;
        }
    }
    return 1;
}
bool isPalindrome(string s) {
    string temp="";
    for(int i=0; i<s.length(); i++)
    {
        if(isValid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    for(int j=0; j<temp.length();j++)
    {
        temp[j]=toLower(temp[j]);
    }
    cout<<temp<<endl;
    return checkPallindrome(temp);
}
int main(){
    string s="Zeus was deified, saw Suez.";
    cout<<(isPalindrome(s));
}
*/

/*
// Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.

#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char> &chars)
{
    int count = 1;
    string temp = "";
    for (int i = 0; i < chars.size(); i++)
    {
        if (chars[i] == chars[i + 1])
        {
            count++;
        }
        else
        {
            temp += chars[i];
            if (count > 1)
            {
                temp += to_string(count);
            }
            count = 1;
        }
    }
    temp += chars[chars.size() - 1];
    if (count > 1)
    {
        temp += to_string(count);
    }
    return temp.length();
}
int main()
{
    vector<char> chars{'a', 'b', 'b', 'b', 'c', 'c', 'c', 'c'};
    cout << compress(chars) << endl;
    return 0;
}

*/










/*
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
// Example 1:
// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
        vector<char>v;
        v.push_back(s[0]); 
        for(int i=1; i<s.size(); i++)
        {
            if(v.size()>0)
            {
                if(s[i]==v.back())
                {
                    v.pop_back();
                }
                else
                {
                   v.push_back(s[i]); 
                }
            }
            else
            {
                v.push_back(s[i]);
            }
            
        }  
        string st="";
        for (int i=0; i<v.size(); i++)
        {
            st+=v[i];
        }
        return st;
}

int main()
{
    string s = "aabcccd";
    cout << removeDuplicates(s) << endl;
    return 0;
}
*/






#include<bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2) 
{
    int end=s1.size()-1;
    for (int i = 0; i < end; i++)
    {
        int j=i;
        while(i==end)
        {
            swap(s1[i],s1[end+i]);
        }
    }
    
}

int main()
{
    string s1="ABC";
    string s1="ACB";

    return 0;
}

