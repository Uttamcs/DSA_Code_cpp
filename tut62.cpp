/*
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;

    node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root)
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"For inserting in left of "<<data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"For inserting in right of "<<data<<endl;
    root -> right = buildTree(root -> right);

    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty())
            {
                // queue still have some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp -> data<<" ";
            if(temp -> left)
            {
                q.push(temp -> left);
            }

            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
    }
}
void inOrder(node* root){
    // base case
    if(root == NULL)
    {
        return;
    }

    inOrder(root -> left);
    cout<<root -> data<<" ";
    inOrder(root -> right);

}
void preorder(node * root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node* root = NULL;
    // creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    levelOrderTraversal(root);
    // cout<<endl<<"Inorder of the root is: "<<endl;
    // inOrder(root);

    // cout<<endl<<"Preorder of the root is: "<<endl;
    // preorder(root);

    // cout<<endl<<"Postorder of the root is: "<<endl;
    // postorder(root);
    return 0;
}
*/














/*
// Build tree using level order traversal

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;

    node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void buildFromLevelOrder(node* &root)
{
    queue<node*>q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node * temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp -> left = new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp -> right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty())
            {
                // queue still have some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp -> data<<" ";
            if(temp -> left)
            {
                q.push(temp -> left);
            }

            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
    }
}
int main()
{
    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    return 0;
}

*/







/*
// Count number of leafs

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
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
void inOrder(node *root, int &cnt)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, cnt);
    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        cnt += 1;
    }
    inOrder(root->right, cnt);
}
int noOfLeafNodes(node *root)
{
    int cnt = 0;
    inOrder(root, cnt);
    return cnt;
}
int main()
{
    node* root =NULL;
    buildFromLevelOrder(root);
    cout<<noOfLeafNodes(root)<<endl;
    return 0;
}




*/