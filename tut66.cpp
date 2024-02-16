/*
// Construct tree from inorder and preorder

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
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
int findPosition(int in[], int element, int inOrderStart, int inOrderEnd)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if(in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    // base case
    if(index>= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = pre[index++]; 
    node* root = new node(element);
    int position = findPosition(in, element, inOrderStart, inOrderEnd);
    cout<<"Position: "<<position<<endl;
    // recursive calls
    root->left =solve(in, pre, index,inOrderStart, position-1,n);
    root->right =solve(in, pre, index,position+1, inOrderEnd,n);
    return root;
}
node* buildTree(int in[], int pre[], int n)
{
    int preOrderIndex =0;
    node* ans= solve(in, pre, preOrderIndex, 0, n-1,n);
    return ans;
}
void postOrderTraversal(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    int n=7;
    int in[7] = {7 ,3, 11 ,1 ,17 ,3 ,18};
    int pre[7] = {1 ,3 ,7 ,11 ,3 ,17 ,18};
    node* ans = buildTree(in, pre,n);
    postOrderTraversal(ans);
    return 0;
}
*/











// Construct the Binary Tree from Postorder and Inorder Traversal


#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data =data;
        this->left= NULL;
        this->right= NULL;
    }
};

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for(int i=0; i<n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}
Node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int>&nodeToIndex)
{
    // base case
    if(index <0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // create a root node for element
    int element = post[index--];
    Node* root = new Node(element);
    
    // find element's index in inOrder
    int position = nodeToIndex[element];
    
    // recursive calls [in case of PostOrder and inOrder, we first build the right]
    root->right = solve(in, post, index, position+1, inOrderEnd, n,nodeToIndex);
    root->left = solve(in, post, index, inOrderStart, position -1, n,nodeToIndex);
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex =n-1;
    map<int, int> nodeToIndex;
    // create nodes to index mapping
    createMapping(in, nodeToIndex, n);
    
    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
    return ans;
}
void preOrder(Node* root)
{
    //  base case
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    int n = 8;
    int in[n] =  {4, 8 ,2 ,5 ,1 ,6, 3 ,7};
    int post[n] ={8, 4 ,5, 2 ,6, 7, 3 ,1,};
    Node* ans = buildTree(in, post, n);
    preOrder(ans);
    return 0;
}
