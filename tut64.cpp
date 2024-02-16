/*
// Zig-Zag Traversal of a BinarY tree

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
vector<int> zigzagTraversal(node* root)
{
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }
    queue<node*> q;
    q.push(root);
    bool lefttoRight = true;
    while(!q.empty())
    {
        int size = q.size();
        cout<<"Size: "<<size<<endl;
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            node* frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = lefttoRight ? i : size - i-1;
            ans[index] = frontNode -> data;

            if(frontNode -> left)
            {
                q.push(frontNode -> left);
            }
            if(frontNode -> right)
            {
                q.push(frontNode -> right);
            }
        }
        // direction v to change karni hai
        lefttoRight = !lefttoRight;
        for(auto i:ans)
        {
            result.push_back(i);
        }
    }
    return result;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(4);
    vector<int> ans = zigzagTraversal(root);
    for(int digit: ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}

*/










/*


// Boundary traversal of Binary tree

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
void traverseleft(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseleft(root->left, ans);
    }
    else
    {
        traverseleft(root->right, ans);
    }
}
void traverseLeaf(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    // wapas aa gye
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left wale ko traverse karo ans store karo
    traverseleft(root->left, ans);

    // leaf node ko traverse and store karo

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // right wale ko traverse karo
    traverseRight(root->right, ans);
    return ans;
}
int main()
{
    node* root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);
    vector<int> ans = boundaryTraversal(root);
    for (auto digit : ans)
    {
        cout << digit << " ";
    }
    return 0;
}
*/













/*

// Vertical Traversal of Binary tree


#include<bits/stdc++.h>
using namespace std;
class node
{
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

vector<int> verticalOrderTraversal(node* root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0,0)));

    while (!q.empty())
    {
        pair<node*, pair<int, int>> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horidist = temp.second.first;
        int level = temp.second.second;


        nodes[horidist][level].push_back(frontNode -> data);

        if(frontNode -> left)
        {
            q.push(make_pair(frontNode->left , make_pair(horidist - 1 , level + 1)));
        } 
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right , make_pair(horidist + 1, level +1)));
        }
    }
    for(auto i: nodes)
    {
        for(auto j: i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right= new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    vector<int> ans = verticalOrderTraversal(root);
    for(auto digit: ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}
*/









/*
// TOP VIEW

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
vector<int> Topview(node* root)
{
    vector<int>ans;
    if(root == NULL)
    {
        return ans;
    }
    map<int, int> topNode;
    queue<pair<node*, int> >q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node*, int> temp =q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a hd then do nothing
        if(topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i:topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right= new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    vector<int> ans =Topview(root);
    for(int digit:ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}
*/









/*
// BOTTOM VIEW

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
vector<int> bottomiew(node* root)
{
    vector<int>ans;
    if(root == NULL)
    {
        return ans;
    }
    map<int, int> topNode;
    queue<pair<node*, int> >q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node*, int> temp =q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a hd then assign new Value
        topNode[hd] = frontNode->data;
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i:topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right= new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    vector<int> ans =bottomiew(root);
    for(int digit:ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}
*/












/*

// LEFT VIEW
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
void solve(node* root, vector<int>&ans, int level)
{
    // base case
    if(root == NULL)
    {
        return ;
    }
    // we entered into a new level
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left , ans, level+1);
    solve(root->right , ans, level+1);
}
vector<int> leftView(node* root)
{
    vector<int>ans;
    solve(root, ans, 0 );
    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right= new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    vector<int> ans =leftView(root);
    for(int digit:ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}

*/









/*
// RIGHT VIEW
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
void solve(node* root, vector<int>&ans, int level)
{
    // base case
    if(root == NULL)
    {
        return ;
    }
    // we entered into a new level
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->right , ans, level+1);
    solve(root->left , ans, level+1);
}
vector<int> rightView(node* root)
{
    vector<int>ans;
    solve(root, ans, 0 );
    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right= new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    vector<int> ans =rightView(root);
    for(int digit:ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}

*/


