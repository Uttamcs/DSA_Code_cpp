// Given a Linked list of size N of integers. the task is to check if the given linked list is pallindrome or not.

// Approach - 1
// -> Linked List ke data ko array me kar do
// -> Phir array me pallindrome check kar do

/*
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
void inserAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
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
        inserAtTail(tail, d);
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
bool chkPallindrome(vector<int> arr){
    int len = arr.size();
    int s = 0;
    int e = len-1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
bool isPallindrome(Node* head)
{
    vector <int> arr;
    while (head != NULL)
    {
        arr.push_back(head -> data);
        head = head -> next;
    }
    return chkPallindrome(arr);
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head , 45);
    insertAtHead(head , 50);
    insertAtHead(head , 45);
    insertAtHead(head , 10);
    print(head);
    cout<<isPallindrome(head);
    return 0;
}
*/




// Approach - 2
//  -> Linked List ka mid find kar lo
//  -> Aur mid ke aage Linked link ko reverse kar do
//  -> phir (head == mid-> next ) hai ki nahi check karte jao



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
void inserAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
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
        inserAtTail(tail, d);
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
Node* findMid(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head -> next;
    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
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
bool isPallindrome(Node* &head)
{
    if (head -> next == NULL)
    {
        return true;
    }
    // Step -1  (find mid)
    Node* mid = findMid(head);

    // step-2   (reverse list after middle)
    Node* reversed =reverse(mid ->next);

    //Step - 3 (mid ke aage reverse wala lagao)
    mid -> next = reversed;

    // Step - 4 ( Compare both list)
    Node* head1 = head;
    Node* head2 = mid -> next ;
    while (head2 != NULL)
    {
        if (head1 -> data != head2 -> data)
        {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return true;
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head , 45);
    insertAtHead(head , 50);
    insertAtHead(head , 45);
    insertAtHead(head , 10);
    print(head);
    cout<<"After reversing List"<<endl;
    if(isPallindrome(head))
    {
        cout<<"Pallindrome"<<endl;
    }
    else
    {
        cout<<"Not a Pallindrome"<<endl;
    }
    return 0;
}