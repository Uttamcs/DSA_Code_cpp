
// Morris Traversal

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL; 
    }
};
vector<int> InorderTraversal(node *root)
{
    vector<int> inorder;
    node *curr = root;
    while (curr != NULL)
    {
        // If there is no left subtree in the binary tree
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        // if there is left subtree in the tree
        else
        {
            node *prev = curr->left;

            // bas prev ke right me aage badhte jao
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            // agar previous ka right null hua tohh
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            // agar prev ka right non-null hai to
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}
int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    // root->left->right->right = new node(6);
    vector<int> ans = InorderTraversal(root);
    for (auto digit : ans)
    {
        cout << digit << " ";
    }
    return 0;
}





/*

// Flatten Binary Tree to linked list

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void flatten(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
void inorder(node *root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);
    flatten(root);
    inorder(root);
    return 0;
}
 
*/