/*
// Sum of the longest Bloodline of a tree (Sum of nodes on the longest path from root to leaf node)


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
        this->left= NULL;
        this->right= NULL;
    }
};
void solve(node* root, int sum , int &maxSum, int len, int &maxLen)
{
    // base case
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}
int sumOfLongRootToLeafPath(node* root)
{
    int len =0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = 0;

    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
int main()
{
    node* root = new node(1);
    root->left = new node(5);
    root->left->left = new node(7);
    root->right = new node(11);
    root->right->right = new node(13);
    cout<<sumOfLongRootToLeafPath(root);
    return 0;
}
*/

/*
#include <bits/stdc++.h>
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
        this->left= NULL;
        this->right= NULL;
    }
};

//Function to return the lowest common ancestor in a Binary Tree.
node* lca(node* root ,int n1 ,int n2 )
{
    //base case
    if(root == NULL)
    {
        return NULL;
    }

    if(root-> data == n1 || root-> data == n2)
    {
        return root;
    }
    node* leftAns = lca(root-> left, n1, n2);
    node* rightAns = lca(root-> right, n1, n2);

    if(leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if(leftAns != NULL  && rightAns == NULL)
    {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns !=NULL)
    {
        return rightAns;
    }
    else
        return NULL;
}
int main()
{
    node* root = new node(1);
    root->left = new node(5);
    root->left->left = new node(7);
    root->right = new node(11);
    root->right->right = new node(13);
    root->right->left = new node(41);
    node* ans= lca(root, 41,13);
    cout<<ans->data<<endl;
    return 0;
}
*/

/*

// KSum paths

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

void solve(node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);

    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}
int kSum(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}
int main()
{
    node *root = new node(1);
    root->left = new node(5);
    root->left->left = new node(7);
    root->right = new node(11);
    root->right->right = new node(13);
    root->right->left = new node(41);
    int k = 13;
    int ans = kSum(root, k);
    cout << ans << endl;
    return 0;
}


*/















// Kth Ancestor in a Tree

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

node *solve(node *root, int &k, int key)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    node *leftAns = solve(root->left, k, key);
    node *rightAns = solve(root->right, k, key);

    if (leftAns != NULL && rightAns == NULL)
    {
        cout<<"pehla wala chal gya ji \n";
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        cout<<"dusra wala chal gya ji \n";
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(node *root, int k, int key)
{
    node *ans = solve(root, k, key);
    if (ans == NULL || ans->data == key)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(5);
    root->left->left = new node(7);
    root->right = new node(11);
    root->right->right = new node(13);
    root->right->left = new node(41);
    int k = 1;
    int key = 7;
    int ans = kthAncestor(root, k, key);
    cout << ans << endl;
    return 0;
}
















/*

// Maximum sum of Non-adjacent nodes

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
pair<int, int> solve(node* root)
{
    // base case
    if(root == NULL)
    {
        return make_pair(0,0);
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}
int getMaxSum(node* root)
{
    pair<int, int> p =solve(root);
    return max(p.first, p.second);
}
int main()
{
    node *root = new node(1);
    root->left = new node(5);
    root->left->left = new node(7);
    root->right = new node(11);
    root->right->right = new node(13);
    root->right->left = new node(41);
    int ans= getMaxSum(root);
    cout<<ans<<endl;
    return 0;
}

*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum(vector<ll> &vc, ll k)
{
    ll total = 0;
    for (ll i = k; i < vc.size(); i++)
    {
        total += vc[i];
    }
    return total;
}
ll solve(vector<ll> &vc, ll &count)
{
    ll left_sum = 0;
    ll rem_sum;
    for (ll i = 0; i < vc.size(); i++)
    {
        left_sum += vc[i];
        rem_sum = sum(vc, i);
        cout << "left_sum: " << left_sum << endl;
        cout << "rem_size: " << rem_sum << endl
             << endl
             << endl;
        if (left_sum * 2 == rem_sum)
        {
            count++;
            left_sum = 0;
        }
    }
    return count;
}

int main()
{
    vector<ll> vc = {4, 0, 1, 0, 1, 1, 0, 1};
    ll n = vc.size();
    ll count = 0;
    cout << solve(vc, count) << endl;
    return 0;
}
*/