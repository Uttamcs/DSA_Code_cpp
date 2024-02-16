
//                       Reverse a Linked List




/*
// Approach-1   (Iteration method)
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
        this->next=NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    temp->next = NULL;
}
void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    // new node creation
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* reverse(Node* head)
{
    if (head == NULL || head-> next == NULL)
    {
        return head;
    }
    
    Node* prev=NULL;
    Node* curr=head;
    while (curr != NULL)
    {
    Node* forward=curr-> next;
    curr ->next=prev;
    prev=curr;
    curr=forward;
    }
    return prev;
}
int main()
{
    Node* node1 = new Node(11);
    Node* head=node1;
    Node* tail=node1;
    insertAttail(tail,22);
    insertAttail(tail,45);
    insertAttail(tail,69);
    print(head);
    cout<<"After reversing Node will be like this:- "<<endl;
    Node* ans=reverse(head);
    print(ans);
    return 0;
}
*/





/*
// Approach-2   (Recursive-1)

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
        this->next=NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    temp->next = NULL;
}
void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    // new node creation
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse(Node* &head, Node* curr, Node* prev)
{
    // base case
    if (curr == NULL)
    {
        head=prev;
        return ;
    }
    
    Node* forward= curr->next;
    reverse(head,forward, curr);
    curr-> next=prev;
}
Node* reverseLinkedList(Node* head)
{
    Node* curr=head;
    Node* prev= NULL;
    reverse(head, curr, prev);
    return head;
}
int main()
{
    Node* node1 = new Node(11);
    Node* head=node1;
    Node* tail=node1;
    insertAttail(tail,22);
    insertAttail(tail,45);
    insertAttail(tail,69);
    print(head);
    cout<<"After reversing Node will be like this:- "<<endl;
    Node* ans=reverseLinkedList(head);
    print(ans);
    return 0;
}
*/









/*
// Approach-3   (Recursive-2)

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
        this->next=NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    temp->next = NULL;
}
void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    // new node creation
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* reverse(Node* head)
{
    if (head == NULL || head-> next== NULL)
    {
        return head;
    }
    Node* chotaHead= reverse(head -> next);
    head -> next -> next=head;
    head -> next =NULL;
    return chotaHead;
}
int main()
{
    Node* node1 = new Node(11);
    Node* head=node1;
    Node* tail=node1;
    insertAttail(tail,22);
    insertAttail(tail,45);
    insertAttail(tail,69);
    print(head);
    cout<<"After reversing Node will be like this:- "<<endl;
    Node* ans=reverse(head);
    print(ans);
    return 0;
}
*/










//                      MIDDLE OF LINKED LIST



/*
// Approach - 1

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
        this->next=NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    temp->next = NULL;
}
void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    // new node creation
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node* head)
{
    Node* temp=head;
    int cnt=0;
    while (temp != NULL)
    {
        cnt++;
        temp= temp-> next;
    }
    return cnt;
}
Node* findMiddle(Node* head)
{
    int len= getLength(head);
    int ans= len/2;

    Node* temp= head;
    int cnt=0;
    while (cnt < ans)
    {
        temp = temp-> next;
        cnt++;
    }
    return temp;
}
int main()
{
    Node* node1 = new Node(11);
    Node* head=node1;
    Node* tail=node1;
    insertAttail(tail,22);
    insertAttail(tail,45);
    insertAttail(tail,69);
    insertAttail(tail,84);
    print(head);
    // cout<<"Length= "<<getLength(head)<<endl;
    int ans= findMiddle(head) -> data;
    cout<<"Middle= "<<ans<<endl;
    return 0;
}

*/
















/*
// Approach - 2

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
        this->next=NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
    temp->next = NULL;
}
void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }
    // new node creation
    Node *NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}
void print(Node* &head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node* head)
{
    Node* temp=head;
    int cnt=0;
    while (temp != NULL)
    {
        cnt++;
        temp= temp-> next;
    }
    return cnt;
}
Node* findMiddle(Node* head)
{
    if (head == NULL || head -> next ==  NULL)
    {
        return head;
    }
    // 2 nodes k liye
    if (head -> next -> next == NULL)
    {
        return head -> next;
    }
    Node* slow= head;
    Node* fast= head -> next;
    while (fast != NULL)
    {
        fast= fast-> next;
        if (fast != NULL)
        {
            fast= fast-> next;
        }
        slow = slow -> next;
    }
    return slow;
}
int main()
{
    Node* node1 = new Node(11);
    Node* head=node1;
    Node* tail=node1;
    insertAttail(tail,22);
    insertAttail(tail,45);
    insertAttail(tail,69);
    insertAttail(tail,84);
    print(head);
    // cout<<"Length= "<<getLength(head)<<endl;
    int ans= findMiddle(head) -> data;
    cout<<"Middle= "<<ans<<endl;
    return 0;
}
*/


