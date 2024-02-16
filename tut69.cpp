
// INSERT A NODE INTO BST


#include<bits/stdc++.h>
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
node* insertIntoBST(node* &root, int d)
{
    // base case
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }
    if(d > root-> data)
    {
        // right part me insert karna hai
        root->right = insertIntoBST(root->right , d);
    }
    else
    {
        // left part me insert karna hai
        root->left = insertIntoBST(root->left , d);
    }
    return root;
}
void take_input(node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
vector<int> levelOrderTraversal(node* root)
{
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        ans.push_back(temp->data);
    }
    return ans;
}
int main()
{
    node *root = NULL;

    cout<<"Enter data to create BST"<<endl;
    take_input(root);
    vector<int>ans = levelOrderTraversal(root);
    cout<<"Printing levelOrderTraversal"<<endl;
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    return 0;
}


/*


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
        this->right =NULL;
    }
};

// // ITERATIVE APPROACH
// bool searchIntoBST(node* root, int x)
// {
//     node* temp = root;
//     while (temp != NULL)
//     {
//         if(temp -> data == x)
//         {
//             return true;
//         }
//         if(temp ->data > x)
//         {
//             temp = temp -> left;
//         }
//         else
//         {
//             temp = temp -> right;
//         }
//     }
//     return false;
// }


// RECURSIVE APPROACH
bool searchIntoBST(node* &root, int x)
{
    if(root == NULL)
    {
        return false;
    }
    if(root -> data == x)
    {
        return true;
    }
    if(root->data > x)
    {
        return searchIntoBST(root->left , x);
    }
    else
    {
        return searchIntoBST(root->right,x);
    }
}
node* insertIntoBST(node* &root, int d)
{
    // base case
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }
    if(d > root-> data)
    {
        // right part me insert karna hai
        root->right = insertIntoBST(root->right , d);
    }
    else
    {
        // left part me insert karna hai
        root->left = insertIntoBST(root->left , d);
    }
    return root;
}
void take_input(node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
int main()
{
    node* root = NULL;
    cout<<"Enter data to create BST "<<endl;
    take_input(root);
    if(searchIntoBST(root, 5))
    {
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
    return 0;
}
*/

/*
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
node* findMin(node* root)
{
    node* temp = root;
    while(temp -> left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node* findMax(node* root)
{
    node* temp = root;
    while(temp -> right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
node* insertIntoBST(node* &root, int data)
{
    // base case
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }
    if(data > root -> data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void take_input(node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
int main()
{
    node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    take_input(root);
    cout<<"Maximum of the tree is "<<findMax(root)->data<<endl;
    cout<<"Minimum of the tree is "<<findMin(root)->data<<endl;
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
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node* deleteFromBST(node* &root, int target)
{
    // base case
    if(root == NULL)
    {
        return root;
    }

    if(root ->data == target)
    {
        // no leaf node



        // one leaf node


        // two leaf node
        
    }
}
node *insertIntoBST(node *&root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void take_input(node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}
int main()
{
    node *root = NULL;
    int target;
    cout << "Enter data to create BST" << endl;
    take_input(root);
    cout << "Enter value of node to be deleted" << endl;
    cin >> target;
}
*/