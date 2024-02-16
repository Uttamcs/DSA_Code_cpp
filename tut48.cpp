/*

// Remove duplicates from a sorted linked List
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
void inserAtPos(Node *&head, Node *&tail, int position, int d)
{
    // if pos is equal to 1
    if (position == 1)
    {
        InsertAtHead(head, d);
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
void removeDuplicates(Node *&head)
{
    Node *curr = head;
    // empty linked list
    if (curr == NULL)
    {
        return;
    }
    while (curr != NULL)
    {
        if ((curr -> next != NULL) && (curr-> data == curr-> next->data))
        {
            Node* next_next=curr-> next ->next;
            Node* NodetoDelete= curr-> next;
            delete(NodetoDelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr ->next;
        }
    }
    return ;
}
int main()
{
    Node *node1 = new Node(15);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 12);

    InsertAtTail(tail, 55);
    InsertAtTail(tail, 77);
    inserAtPos(head, tail, 4, 55);
    inserAtPos(head, tail, 1, 5);
    print(head);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    removeDuplicates(head);
    print(head);
    return 0;
}
*/






























//          Remove duplicates from a unsorted Linked List

/*

//Approach - 1    (2 loop wala method)


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
void inserAtPos(Node *&head, Node *&tail, int position, int d)
{
    // if pos is equal to 1
    if (position == 1)
    {
        InsertAtHead(head, d);
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

void removeDuplicate(Node* &head)
{
    Node* temp1 = head;
    while (temp1 != NULL)
    {
        Node* temp2 = temp1 -> next;
        Node* prev = temp1;
        while (temp2  != NULL)
        {
            if (temp1 -> data == temp2 -> data)
            {
                Node* nodeToDelete = temp2;
                temp2 = temp2 -> next;
                prev -> next = temp2;
                delete nodeToDelete;
            }
            prev = prev -> next;
            temp2= temp2-> next;
        }
        temp1 = temp1 -> next;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    InsertAtHead(head, 15);
    InsertAtTail(tail, 121);
    InsertAtTail(tail, 51);
    inserAtPos(head, tail, 4, 555);
    InsertAtTail(tail, 45);
    inserAtPos(head, tail, 1, 121);
    print(head);
    cout<<endl;
    removeDuplicate(head);
    print(head);
    return 0;
}
*/













// Approach - 2 (Bubble sort Approach)

/*
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
void inserAtPos(Node *&head, Node *&tail, int position, int d)
{
    // if pos is equal to 1
    if (position == 1)
    {
        InsertAtHead(head, d);
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
void bubbleSortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;
    Node* current;
    Node* last = nullptr;

    do
    {
        swapped = false;
        current = head;
        while (current -> next != NULL)
        {
            if (current -> data > current -> next -> data)
            {
                swap(current -> data , current -> next -> data);
                swapped = true;
            }
            current = current -> next;
        }
        last = current ;
    } while (swapped);
}
void removeDuplicates(Node *&head)
{
    bubbleSortLinkedList(head);
    Node *curr = head;
    // empty linked list
    if (curr == NULL)
    {
        return;
    }
    while (curr != NULL)
    {
        if ((curr -> next != NULL) && (curr-> data == curr-> next->data))
        {
            Node* next_next=curr-> next ->next;
            Node* NodetoDelete= curr-> next;
            delete(NodetoDelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr ->next;
        }
    }
    return ;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    InsertAtHead(head, 15);
    InsertAtTail(tail, 121);
    InsertAtTail(tail, 51);
    inserAtPos(head, tail, 4, 555);
    InsertAtTail(tail, 45);
    inserAtPos(head, tail, 1, 121);
    print(head);
    cout<<endl;
    removeDuplicates(head);
    print(head);
    return 0;
}
*/








/*

// Approach - 3

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
void inserAtPos(Node *&head, Node *&tail, int position, int d)
{
    // if pos is equal to 1
    if (position == 1)
    {
        InsertAtHead(head, d);
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

void removeDuplicates(Node *&head)
{
    Node* temp = head;
    if (temp -> next == NULL)
    {
        return ;
    }
    map<int , bool> visited;
    Node* prev =NULL;
    while (temp != NULL)
    {
        if (visited[temp -> data] == true)
        {
            prev -> next = temp -> next ;
            delete temp;
            temp = prev -> next ;
        }
        else
        {
            visited[temp -> data] = true;
            prev = temp;
            temp = temp -> next;
        }
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    InsertAtHead(head, 15);
    InsertAtTail(tail, 121);
    InsertAtTail(tail, 51);
    inserAtPos(head, tail, 4, 555);
    InsertAtTail(tail, 45);
    inserAtPos(head, tail, 1, 121);
    print(head);
    cout<<"Duplicates element ko delete karne k baad"<<endl;
    removeDuplicates(head);
    print(head);
    return 0;
}
*/