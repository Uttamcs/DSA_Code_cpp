// You are given a linked list having N number of nodes and each node will have an integer which can be 0, 1, and 2.
//  You have to sort the given linked list in ascending order


/*
// Approach-1
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

void InsertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node *&tail, int e)
{
    // new node create
    Node *temp = new Node(e);
    tail->next = temp;
    tail = temp;
}
void insertatPos(Node *&head, Node *&tail, int pos, int d)
{
    // if we want to add at first position
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *sort(Node *head)
{
    int oneCount = 0;
    int twoCount = 0;
    int zeroCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if(temp->data ==2)
        {
            twoCount++;
        }
        temp=temp->next;
    }
    temp=head;
    while (temp !=NULL)
    {
        if (zeroCount != 0)
        {
            temp->data =0 ;
            zeroCount--;
        }
        else if(oneCount !=0 )
        {
            temp->data= 1;
            oneCount--;
        }
        else if(twoCount != 0)
        {
            temp->data= 2;
            twoCount--;
        }
       temp=temp->next;
    }
    return head;
}
int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 0);
    InsertAtHead(head, 1);
    InsertAtTail(tail, 2);
    insertatPos(head, tail, 3, 2);
    InsertAtTail(tail, 0);
    InsertAtTail(tail, 0);
    print(head);

    cout<<"After sorting"<<endl;
    sort(head);
    print(head);
    return 0;
}
*/














/*

// Approach-2

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

void InsertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void InsertAtTail(Node* &tail, int e)
{
    // new node create
    Node *temp = new Node(e);
    if(tail ==NULL)
    {
        tail = temp;
        return ;
    }
    tail->next = temp;
    tail = temp;
}
void insertatPos(Node *&head, Node *&tail, int pos, int d)
{
    // if we want to add at first position
    if (pos == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void populate(Node* &tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *sort(Node *&head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            populate(zeroTail, curr);
        }
        else if (value == 1)
        {
            populate(oneTail, curr);
        }
        else if (value == 2)
        {
            populate(twoTail, curr);
        }
        curr = curr->next;
    }

    // 1's list is not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1's list is empty
        zeroTail->next = twoHead->next;
    }
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}


int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 0);
    InsertAtHead(head, 1);
    InsertAtTail(tail, 2);
    insertatPos(head, tail, 3, 2);
    InsertAtTail(tail, 0);
    InsertAtTail(tail, 0);
    print(head);

    cout << "After sorting" << endl;
    sort(head);
    print(head);
    return 0;
}
*/










//                          MERGE TWO SORTED LINKED LIST    


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
Node* solve(Node* &first, Node* &second)
{
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    while (curr1 != NULL && curr2 != NULL)
    {
        if ((curr1 -> data <= curr2 -> data )&&(curr2-> data <= next1 -> data))
        {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1= curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1 -> next;
            if (next1 == NULL)
            {
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node* mergetwolist(Node* &node1,Node* &node2)
{
    Node* temp1 = node1;
    Node* temp2 = node2;
    if (node1 == NULL)
    {
        return node2;
    }
    if(node2 == NULL)
    {
        return node1;
    }
    if (node1 -> data <= node2 -> data)
    {
        return solve(node1 , node2);
    }
    else
    {
        return solve(node2, node1);
    }
}
int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(6);
    Node* head1 = node1;
    Node* head2 = node2;
    Node* tail1 = node1;
    Node* tail2 = node2;
    insertAtTail(tail1 , 9);
    insertAtTail(tail1 , 16);
    insertAtTail(tail1 , 19);
    insertAtTail(tail1 , 152);
    insertAtTail(tail2 , 12);
    insertAtTail(tail2 , 22);
    insertAtTail(tail2 , 27);
    insertAtTail(tail2 , 122);
    print(head1);
    print(head2);
    cout<<"After merging both the arrays"<<endl;
    mergetwolist(head1, head2);
    print(head1);
    return 0;
}