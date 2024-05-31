#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount =0;

    TrieNode(char ch)
    {
        data= ch;
        for (size_t i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode* child;


        // present
        if(root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[idx] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string& ans)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if(root->childCount == 1)
            {
                ans+=ch;

                // aage badhao
                int idx = ch - 'a';
                root= root->children[idx];
            }
            else
            {
                break;
            }

            if(root->isTerminal)
            {
                break;
            }
        }
        
    }
}; 
int main()
{
    vector<string>vc = {"aba", "abab", ""};
    int n = vc.size();
    Trie* t = new Trie('\0');
    for (size_t i = 0; i < n; i++)
    {
        t->insertWord(vc[i]);
    }
    string ans = "";
    string first = vc[0];
    t->lcp(first, ans);
    cout<<ans<<endl;
    return 0;
}