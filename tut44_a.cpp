//                      LINKED LIST

/*
#include<bits/stdc++.h>
using namespace std;
class Node{                                                   
    public:
    int data;
    Node *next;

    // constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
int main()
{
    Node *node1=new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    return 0;
}
*/












/*
// Insert a new element at start, last and at specific position
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
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
void inserAtPos(Node* &head, Node* &tail, int position, int d){
    // if pos is equal to 1
    if (position==1)
    {
        InsertAtHead(head,d);
        return ;
    }

    Node* temp= head;
    int count=1;
    while (count < position-1)
    {
        temp=temp->next;
        count++;
    }
    if (temp->next==NULL)
    {
        InsertAtTail(tail, d);
        return ;
    }
    
    Node* NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
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

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 15);
    print(head);

    InsertAtTail(tail, 45);
    print(head);
    InsertAtTail(tail, 51);
    print(head);
    inserAtPos(head, tail, 4,555);
    print(head);
    inserAtPos(head, tail, 1,121);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}
*/













/*
//  Deletion of an element of given position in a linked list
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value=this->data;
        if (this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
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
void inserAtPos(Node* &head, Node* &tail, int position, int d){
    // if pos is equal to 1
    if (position==1)
    {
        InsertAtHead(head,d);
        return ;
    }

    Node* temp= head;
    int count=1;
    while (count < position-1)
    {
        temp=temp->next;
        count++;
    }
    if (temp->next==NULL)
    {
        InsertAtTail(tail, d);
        return ;
    }
    
    Node* NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
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
void deleteNode(int position, Node* &head){
    if (position==1)
    {
        Node* temp=head;
        head=head->next;
        // memory free kar do start node ka 
        temp->next=NULL;
        delete temp;
    }
    else
    {
        // deleting any middle or last node
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while (count<position)
        {
            prev=curr;
            curr= curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
    
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 15);
    print(head);

    InsertAtTail(tail, 45);
    print(head);
    InsertAtTail(tail, 51);
    print(head);
    inserAtPos(head, tail, 4,555);
    print(head);
    inserAtPos(head, tail, 1,121);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    deleteNode(2,head);
    print(head);
    return 0;
}
*/








/*
// Deletion of given element in a linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    // Constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head, int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAttail(Node* &tail, int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
    temp->next=NULL;
}
void insertAtPos(Node* &head, Node* &tail, int position, int d){
    if (position == 1 )
    {
        insertAtHead(head, d);
        return;
    }
    
    Node* temp=head;
    int count=1;
    while (count < position - 1)
    {
        temp=temp->next;
        count++;
    }
    if (temp->next==NULL)
    {
        insertAttail(tail, d);
        return;
    }
    // new node creation
    Node* NodeToInsert= new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}
void print(Node* &head){
    Node* temp= head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void toDeleteElement(Node* &head, int element) {
    Node* temp = head;
    Node* prev = NULL;

    // If the element to be deleted is the head node
    if (temp != NULL && temp->data == element) {
        head = temp->next;  // Change the head
        temp->next=NULL;
        delete temp;        // Delete the old head
        return;
    }

    // Find the node with the given element
    while (temp != NULL && temp->data != element) {
        prev = temp;
        temp = temp->next;
    }

    // If the element is not present in the linked list
    if (temp == NULL) {
        cout << "Element not found." << endl;
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = temp->next;

    // Delete the node
    delete temp;
}



// // We c



int main(){
    Node* node1= new Node(5);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtHead(head, 25);
    print(head);
    insertAtHead(head, 3);
    print(head);
    toDeleteElement(head,3);
    print(head);
    return 0;
}
*/






