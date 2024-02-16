// Burning Tree

// Given a binary tree and a node called target.Find the minimum time required to burn the complete binary tree if the target is set on fire.
// It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child and parent

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *result = NULL;
    queue<node *> q;
    q.push(root);

    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            result = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}


int burnTree(node *root, map<node *, node *> nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;
    while (!q.empty())
    {
        bool flag = false;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process neighbouring node
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}


int minTime(node *root, int target)
{
    // Algorithm
    // Step 1: create nodeToParent mapping
    // Step 2: find target node
    // Step 3: burn the tree in minimum time
    
    map<node *, node *> nodeToParent;
    node *targetNode = createMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->right = new node(6);
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(10);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    cout << minTime(root, 8) << endl;
    return 0;
}
