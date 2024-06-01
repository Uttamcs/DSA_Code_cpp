//  Implement a phone directory

//https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666
#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (size_t i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
    public:
    TrieNode* root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case 
        if(word.length()== 0)
        {
            root->isTerminal =true;
            return;
        }

        int idx = word[0]-'a';
        TrieNode* child ;

        if(root->children[idx] != NULL)
        {
            // present
            child = root->children[idx];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode* next = curr->children[ i -'a'];

            if(next != NULL)
            {
                prefix.push_back(i);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
        
    }
    vector<vector<string>> getSuggestion(string str)
    {
        TrieNode* prev = root;
        string prefix = "";
        vector<vector<string>> output;
        for (size_t i = 0; i < str.size(); i++)
        {
            char lastChar = str[i];

            prefix.push_back(lastChar);

            // check for lastChar
            TrieNode* curr = prev ->children[lastChar-'a'] ;

            // if not found
            if(curr == NULL)
            {
                break;
            }

            // if found
            vector<string>temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);

            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* t = new Trie('\0');

    for (size_t i = 0; i < contactList.size(); i++)
    {
        string str= contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestion(queryStr);
}
int main()
{
    vector<string> contactList = {"cod" ,"coding", "codding", "code", "coly"};
    string queryStr = "coding";
    vector<vector<string>> ans;
    ans = phoneDirectory(contactList, queryStr);
    for(auto it:ans)
    {
        for(auto itt: it)
        {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}