// Implementation of Trie


#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    int data;
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

    Trie()
    {
        root = new TrieNode('\0');
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
            root->children[idx] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int idx = word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            // absent
            return false;
        }

        // Recursion

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};
int main()
{
    Trie* t= new Trie();
    t->insertWord("abcd");
    cout<<"Present or not "<<t->searchWord("abc");
    return 0;
}