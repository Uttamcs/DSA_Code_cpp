// Largest BST

#include<bits/stdc++.h>
using namespace std;
class node
{
    public :
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class info
{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
info solve(node* root, int& maxSize)
{
    // base case 
    if(root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left , maxSize);
    info right = solve(root->right , maxSize);
    info currNode;
    currNode.size = left.size+right.size+1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data , left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root-> data < right.mini))
    {
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // answer update
    if(currNode.isBST)
    {
        maxSize = max(maxSize, currNode.size);
    }
    return currNode;
}
int main()
{
    node* root = new node(5);
    root->left = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right = new node(4);
    int maxSize = 0;
    info temp = solve(root, maxSize);
    cout<<maxSize<<endl;
    return 0;
}