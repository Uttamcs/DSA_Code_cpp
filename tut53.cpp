// For a given singly Linked List of integers, sort the list using "Merge Sort Algorithm"

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
        }
};
void insertAtPosition(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
    return ;
}
void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    if (tail == NULL)
    {
        tail = temp;
        return ; 
    }
    tail -> next = temp;
    tail = temp;
}
void print(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl<<endl;;
}
Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast =head -> next;

    while (fast!= NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next ;
        }
    }
    return slow;
}
Node* merge(Node* left , Node* right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left -> data <= right -> data)
        {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while (left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while (right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans-> next;
    return ans;
}
Node* mergeSort(Node* &head)
{
    // base case
    if ( head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    // Dividing into two halves after finding mid
    Node* mid = findMid(head);

    Node* leftHalf = head;
    Node* rightHalf = mid -> next;
    mid -> next = NULL;

    // recursive calls to sort two halves
    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    // merge both halves 
    Node* result = merge(leftHalf , rightHalf);

    return result;
}
int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(6);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAtTail(tail1 , 16);
    insertAtTail(tail1 , 9);
    insertAtTail(tail1 , 152);
    insertAtTail(tail1 , 19);
    print(head1);
    cout<<"After sorting the arrays"<<endl;
    head1 = mergeSort(head1);
    print(head1);
    return 0;
}


