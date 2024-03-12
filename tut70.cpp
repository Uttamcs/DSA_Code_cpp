// // find given BST is valid or not

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;

//     node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// bool isBST(node* root, int mini, int maxi)
// {
//     // base case
//     if(root == NULL)
//     {
//         return true;
//     }

//     if(root -> data <= maxi && root -> data >= mini)
//     {
//         bool left = isBST(root -> left , mini, root -> data);
//         bool right = isBST(root -> right, root -> data , maxi);
//         return left && right;
//     }
//     return false;
// }
// int main()
// {
//     node *root = new node(7);
//     root->left = new node(5);
//     root->left->left = new node(3);
//     root->left->right = new node(6);
//     root->right = new node(11);
//     root->right->left = new node(10);
//     root->right->right = new node(15);
//     cout<<isBST(root, INT_MIN, INT_MAX)<<endl;
//     return 0;
// }









// // kth_Smallest in Binary Search Tree

// #include<bits/stdc++.h>
// using namespace std;
// class node{
//     public :
//         int data;
//         node* left;
//         node* right;

//     node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// int kth_Smallest(node* root , int& i, int k)
// {
//     // base case
//     if(root == NULL)
//     {
//         return -1;
//     }

//     int left = kth_Smallest(root -> left, i , k);
//     if(left != -1)
//     {
//         return left;
//     }

//     // node
//     i++;
//     if(i == k)
//     {
//         return root -> data;
//     }

//     // right
//     return kth_Smallest(root->right , i, k);
// }
// int main()
// {
//     int i = 0;
//     node *root = new node(7);
//     root->left = new node(5);
//     root->left->left = new node(3);
//     root->left->right = new node(6);
//     root->right = new node(11);
//     root->right->left = new node(10);
//     root->right->right = new node(15);
//     cout<<kth_Smallest(root, i, 1)<<endl;;
//     return 0;
// }









// // Predecessor and Successor in BST

// #include<bits/stdc++.h>
// using namespace std;
// class node
// {
//     public:
//         int data;
//         node* left ;
//         node* right;

//     node(int data)
//     {
//         this->data = data;
//         this -> left = NULL;
//         this -> right = NULL;
//     }
// };

// pair<int, int> predSucc(node* root , int key)
// {
//     node* temp = root;
//     int pred = -1;
//     int succ = -1;

//     while (temp && temp -> data != key)
//     {
//         if(temp -> data > key)
//         {
//             succ = temp -> data;
//             temp  = temp -> left;
//         }
//         else
//         {
//             pred = temp -> data;
//             temp = temp -> right;
//         }
//     }

//     // pred and succ

//     // pred
//     if(temp)
//     {
//         node* leftTree = temp->left;
//         while (leftTree != NULL)
//         {
//             pred = leftTree -> data;
//             leftTree = leftTree -> right;
//         }
        
//     }


//     // succ
//     if(temp)
//     {
//         node* rightTree = temp->right;
//         while (rightTree != NULL)
//         {
//             pred = rightTree -> data;
//             rightTree = rightTree -> left;
//         }
        
//     }
//     return make_pair(pred, succ);
// }


// int main()
// {
//     node* root = new node(15);
//     root -> left = new node(10);
//     root -> right = new node(20);
//     root -> left -> left = new node(8);
//     root -> left -> right = new node(12);
//     root -> right -> left = new node(16);
//     root -> right -> right = new node(25);
//     pair<int, int> ans = predSucc(root, 8);
//     cout<<ans.first<<" "<<ans.second<<endl;
//     return 0;
// }








// Lowest Common Ancestor

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
node* lca(node* root , node* p , node* q)
{
    // base case
    if(root == NULL) return NULL;

    if (root->data > p->data && root->data >q -> data)
    {
        lca(root->left, p , q);
    }
    if (root->data <  p->data && root->data < q -> data)
    {
        lca(root->right, p , q);
    }
    return root;
}
int main()
{
    node* root = new  node(2);
    root -> left = new node(1);
    root->right = new node(4);
    root->right->left = new node(3);
    node* p = root->left;
    node* q = root->right->left;
    node* ans = lca(root, p , q);
    cout<<ans->data<<endl;
    return 0;
}