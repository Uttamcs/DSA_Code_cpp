// // Two Sum IV - Input is a BST
// // https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0&leftPanelTabValue=PROBLEM

// #include <bits/stdc++.h>
// using namespace std;
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
// void inOrder(node *root, vector<int> &vc)
// {
//     // base case
//     if (root == NULL)
//     {
//         return;
//     }

//     inOrder(root->left, vc);
//     vc.push_back(root->data);
//     inOrder(root->right, vc);
// }
// int main()
// {
//     node *root = new node(10);
//     root->left = new node(6);
//     root->left->left = new node(2);
//     root->left->right = new node(8);
//     root->right = new node(12);
//     root->right->left = new node(11);
//     root->right->right = new node(15);
//     int target = 14;
//     vector<int> vc;
//     bool flag = false;
//     inOrder(root, vc);
//     int si = 0, ei = vc.size() - 1;
//     while (si < ei)
//     {
//         int sum = vc[si] + vc[ei];
//         if (sum == target)
//         {
//             flag = true;
//             break;
//         }
//         if (sum < target)
//             si++;
//         else
//             ei--;
//     }
//     if (flag)
//     {
//         cout << "True" << endl;
//     }
//     else
//     {
//         cout << "False" << endl;
//     }
//     return 0;
// }









// // Flatten BST into a sorted List
// // https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0&leftPanelTabValue=PROBLEM
// #include<bits/stdc++.h>
// using namespace std;
// class node
// {
//     public:
//     int data;
//     node* left;
//     node* right;

//     node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// void inOrder(node *root, vector<int> &vc)
// {
//     // base case
//     if (root == NULL)
//     {
//         return;
//     }

//     inOrder(root->left, vc);
//     vc.push_back(root->data);
//     inOrder(root->right, vc);
// }
// int main()
// {
//     node *root = new node(10);
//     root->left = new node(6);
//     root->left->left = new node(2);
//     root->left->right = new node(8);
//     root->right = new node(12);
//     root->right->left = new node(11);
//     root->right->right = new node(15);
//     vector<int> vc;
//     inOrder(root, vc);
//     int n = vc.size();
//     node* temp = new node(vc[0]);
//     node* curr = temp;
//     for (size_t i = 1; i < n; i++)
//     {
//         node* newRoot = new node(vc[i]);
//         curr-> left = NULL;
//         curr -> right = newRoot;
//         curr = newRoot;
//     }
//     node* tt = temp;
//     while(tt != NULL)
//     {
//         cout<<tt->data<<"-->";
//         tt = tt->right;
//     }
//     cout<<"null";
//     return 0;
// }

















// // Normal BST to Balanced BST
// // https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0

// #include<bits/stdc++.h>
// using namespace std;

// class node
// {
//     public:
//     int data;
//     node* left;
//     node* right;

//     node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// void inOrder(node* root, vector<int>& vc)
// {
//     // base case 
//     if(root == NULL)
//     {
//         return;
//     }

//     inOrder(root -> left, vc);
//     vc.push_back(root -> data);
//     inOrder(root -> right, vc);
// }
// node* inOrderToBST(int s, int e, vector<int>& inOrder)
// {
//     // base case 
//     if(s > e)
//     {
//         return NULL;
//     }

//     int mid = (s+e)/2;
//     node* root = new node(inOrder[mid]);
//     root -> left = inOrderToBST(s, mid - 1, inOrder);
//     root -> right = inOrderToBST(mid + 1,e, inOrder);
//     return root;
// }
// node* main()
// {
//     node* root = new node(10);
//     root -> left = new node(8);
//     root -> left->left= new node(4);
//     root -> left->left->left= new node(2);
//     root -> right = new node(12);
//     root -> right->right= new node(16);
//     root -> right->right->right= new node(20);
//     vector<int>vc;
//     inOrder(root,vc);
//     return inOrderToBST(0, vc.size() -1, vc);
// }











// // PreOrder traversal of a BST
// // https://www.codingninjas.com/studio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0

// #include<bits/stdc++.h>
// using namespace std;
// class node
// {
//     public:
//     int data;
//     node* left;
//     node* right;

//     node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// node* solve(vector<int>preorder, int mini, int maxi, int &i)
// {
//     // base case
//     if( i>= preorder.size()) return NULL;

//     if(preorder[i] < mini || preorder[i] > maxi) return NULL;

//     node* root =new node(preorder[i++]);
//     root -> left = solve(preorder, mini, root -> data, i);
//     root -> right = solve(preorder, root -> data,maxi, i);
//     return root;
// }
// void preOrder(node* root, vector<int>& vc)
// {
//     // base case
//     if(root == NULL)
//     {
//         return;
//     }
//     vc.push_back(root->data);
//     preOrder(root->left, vc);
//     preOrder(root->right, vc);
// }
// node* main()
// {
//     node* root = new node(20);
//     root->left = new node(10);
//     root->left->left = new node(5);
//     root->left->right = new node(15);
//     root->left->right->left = new node(13);
//     root->right = new node(35);
//     root->right->left = new node(30);
//     root->right->right = new node(42);
//     int mini = INT_MIN;
//     int maxi = INT_MAX;
//     int i = 0;
//     vector<int>vc;
//     preOrder(root, vc);
//     return solve(vc, mini, maxi, i);
// }