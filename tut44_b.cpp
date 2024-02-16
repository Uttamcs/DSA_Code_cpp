//                      DOUBLY LINKED LIST

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int val=this->data;
        if (next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};
void insertAtHead(Node *&head,Node* &tail, int d)
{
    if (head == NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else
    {
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}
void insertAtTail(Node* &head, Node* &tail, int d)
{
    if (tail == NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else
    {
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}
void insertAtPos(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head,tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *NodeToInsert = new Node(d);

    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
}
void deleteNode(int position, Node* &head){
    if (position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        // memory free kar do start node ka 
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
        curr->prev=NULL;
        prev->next=curr->next;
        curr-> next=NULL;
        delete curr;
    }
    
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
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    Node *node1 = new Node(15);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    cout<<"Length "<<getLength(head)<<endl;

    insertAtHead(head,tail, 23);
    print(head);

    insertAtHead(head,tail, 5);
    print(head);

    insertAtHead(head,tail, 8);
    print(head);

    insertAtTail(head,tail, 89);
    print(head);

    insertAtPos(head, tail, 3, 155);
    print(head);
    cout<<head->next<<endl;
    cout<<head->prev<<endl;
    
    deleteNode(6, head);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}