// //  Merge Two BSTs
// // https://codingninjas.com/studio/problems/h_920474?leftPanelTab=0&leftPanelTabValue=PROBLEM
//  // Approach -I (Brute force approach)

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
//         this->right =NULL;
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
//     inOrder(root -> right,vc);
// }
// vector<int> mergeTwoSortedArr(vector<int>& vc1, vector<int>& vc2)
// {
//     int vc1Size = vc1.size();
//     int vc2Size = vc2.size();
//     vector<int> ans(vc1Size+vc2Size);

//     int i = 0, j= 0, k=0;
//     while(i<vc1Size && j<vc2Size)
//     {
//         if(vc1[i] < vc2[j])
//         {
//             ans[k++] = vc1[i++];
//         }
//         else
//         {
//             ans[k++] = vc2[j++];
//         }
//     }
//     while(i < vc1Size)
//     {
//         ans[k++] = vc1[i++];
//     }
//     while(j < vc2Size)
//     {
//         ans[k++] = vc2[j++];
//     }
//     return ans;
// }
// node* inorderToBST(int s, int e, vector<int> vc)
// {
//     // base case
//     if(s > e)
//     {
//         return NULL;
//     }

//     int mid = (s+e)/2;
//     node* root = new node(vc[mid]);
//     root -> left = inorderToBST(s,  mid -1 , vc);
//     root -> right = inorderToBST(mid+1,  e, vc);
//     return root;
// }
// vector<int> mergeBST(node* root1, node* root2)
// {
//     // Write your code here.
//     vector<int>in1;
//     vector<int>in2;
//     inOrder(root1, in1);
//     inOrder(root2, in2);
//     vector<int>final =mergeTwoSortedArr(in1, in2);
//     node* temp = inorderToBST(0, final.size()-1, final);
//     vector<int>anss;
//     inOrder(temp, anss);
//     return anss;
// }
// int main()
// {
//     node* root1 = new node(2);
//     root1->left = new node(1);
//     root1-> right = new node(3);
//     node* root2 = new node(4);
//     vector<int>res = mergeBST(root1, root2);
//     for(auto it: res)
//     {
//         cout<<it<<" ";
//     }
//     return 0;
// }
















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

void convertIntoSortedDLL(node* root, node* &head)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    convertIntoSortedDLL(root->left, head);
}

node* mergeLinkedList(node* head1, node* head2)
{
    node* head = NULL;
    node* tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(node* head)
{
    int cnt = 0;
    node* temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

node* sortedLLToBST(node* &head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    node* left = sortedLLToBST(head, n / 2);
    node* root = head;
    root->left = left;

    head = head->right;
    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

int main()
{
    node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);
    node* root2 = new node(4);

    // Step - I: Convert BST into Sorted DLL in-place
    node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    if (head1) head1->left = NULL;

    node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    if (head2) head2->left = NULL;

    // Step -II : Merge sorted Linked List
    node* head = mergeLinkedList(head1, head2);

    // Step - III : Convert SLL into BST
    node* bstRoot = sortedLLToBST(head, countNodes(head));

    return 0;
}
