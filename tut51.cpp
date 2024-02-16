// Add two Numbers represented by two linked lists of size N and M. the task is to return a sum list
// The sum list is a linked list representation of the addition of two input numbers from the list



#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void inserAtTail(Node* &head , Node* &tail, int d)
{
    Node* temp = new Node(d);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail -> next = temp;
        temp -> next = NULL;
        tail = temp;
    }
}
void insertAtPos(Node* &head , Node* &tail , int pos , int d)
{
    if(pos == 1)
    {
        insertAtHead(head , d);
        return ;
    }
    Node* curr = head;
    int count = 1;
    while (count < pos - 1)
    {
        curr = curr -> next;
        count ++;
    }
    if (curr -> next == NULL)
    {
        inserAtTail(head, tail, d);
        return;
    }
    Node* temp = new Node(d);
    temp -> next = curr -> next;
    curr -> next = temp;
}
void print(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
/*
Node* add(Node* &first , Node* &second)
{
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int sum = carry + first -> data + second -> data;
        int digit = sum % 10;
        inserAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        // Aage badhte raho
        first = first -> next;
        second = second -> next;
    }
    while (first != NULL)
    {
        int sum = carry + first -> data;
        int digit = sum %10;
        inserAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        // Aage badhte raho
        first = first -> next;
    }
    while (second != NULL)
    {
        int sum = carry+ second -> data;
        int digit = sum %10;
        inserAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        // Aage badhte raho
        second = second -> next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum %10;
        inserAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
} 
*/

// We can also write add function like this
Node* add(Node* &first , Node* &second)
{
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry !=0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first -> data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second -> data;
        }
        
        int sum = carry + val1 + val2 ;
        int digit = sum % 10;
        inserAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        // Aage badhte raho
        if( first != NULL)
        {
            first = first -> next;  
        }
        if( second != NULL)
        {
            second = second -> next;
        }
    }
    return ansHead;
}
Node* addTwolists(Node* &first, Node* &second)
{

    // Step -1  dono list ko reverse karo
    first = reverse(first);
    second = reverse(second);

    // Step -2  Add two LL
    Node* ans = add(first, second);

    // Reverse the ans LL
    ans = reverse(ans);
    return ans;
}
int main()
{
    Node* node1 = new Node(3);
    Node* node2 = new Node(9);
    Node* head1 = node1;
    Node* tail1 = node1;
    Node* head2 = node2;
    Node* tail2 = node2;
    insertAtHead(head1 , 4);
    insertAtHead(head1 , 0);
    insertAtHead(head1 , 1);
    print(head1); 
    insertAtHead(head2 , 7);
    insertAtHead(head2 , 6);
    insertAtHead(head2 , 7);
    print(head2); 
    Node* sum= addTwolists(head1, head2);
    print(sum);
    return 0;
}