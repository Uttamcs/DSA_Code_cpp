

/*

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

*/







/*
// Search a node in binary search tree


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
node* minVal(node* root)
{
    node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node* maxVal(node* root)
{
    node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
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
        if(root ->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }


        // one leaf node

        // left wala hai tohh
        if(root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // right wala hai tohh

        if(root->left == NULL && root->right != NULL)
        {
            node* temp = root -> right;
            delete root;
            return temp;
        }

        // two leaf node

        if(root->left != NULL && root->right != NULL)
        {
            // root->data = minVal(root->right)-> data;;
            // root->right = deleteFromBST(root->right, root->data);


            root -> data = maxVal(root -> left) -> data;
            root -> left = deleteFromBST(root -> left , root -> data);
            return root;
        }
    }

    if(target < root -> data)
    {
        cout<<"\nye upar wala chlega aur iska value hai "<<root -> data<<"   " <<endl;
        root -> left = deleteFromBST(root -> left , target);
    }
    if(target > root -> data)
    {
        cout<<"\nBhai ye v chal rha hai iska value tohh dekkho "<<root -> data<< "  " <<endl;
        root -> right = deleteFromBST(root -> right , target);
    }
    return root ;
}
void levelOrderTraversal(node* root)
{   
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
void preOrder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
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
    cout<<endl<<"Printing levelOrderTraversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl<<"Printing preOrder"<<endl;
    preOrder(root);
    cout<<endl<<"Printing inOrder"<<endl;
    inOrder(root);
    cout<<endl<<"Printing postOrder"<<endl;
    postOrder(root);
    cout<<"\n chlo ab delete karne chalte hai"<<endl;
    // DELETING NODE FORM BST
    deleteFromBST(root,target);
    cout<<"\nAfter deleting node "<<endl;
    cout<<endl<<"Printing preOrder"<<endl;
    preOrder(root);
    cout<<endl<<"Printing inOrder"<<endl;
    inOrder(root);
    cout<<endl<<"Printing postOrder"<<endl;
    postOrder(root);
    cout<<endl<<"Printing levelOrderTraversal"<<endl;
    levelOrderTraversal(root);
}