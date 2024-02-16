
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
Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // step 1:  Reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step: 2 (Recursion dekhlega aage ka)
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    // Step :3   return head of reverse linked List
    return prev;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    InsertAtTail(tail, 45);
    InsertAtTail(tail, 51);
    inserAtPos(head, tail, 4, 555);
    inserAtPos(head, tail, 1, 121);
    print(head);
    cout<<"After reversing List into group of K elements "<<endl;
    Node *ans = kReverse(head, 3);
    print(ans);
    return 0;
}












/*


// Check given list is circular or not
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node wioth data " << value << endl;
    }
};
void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}
bool isCircular(Node* head)
{
    //empty list
    if (head == NULL)
    {
        return true;
    }
    Node* temp= head->next;
    while (temp != NULL && temp !=head)
    {
        temp= temp-> next;
    }
    if (temp == head)
    {
        return true;
    }
    return false;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 0, 5);

    insertNode(tail, 5, 9);

    insertNode(tail, 9, 841);

    insertNode(tail, 5, 451);

    insertNode(tail, 841, 123);
    print(tail);
    if(isCircular(tail))    //It will be always true bcoz here insertion code is written of circular Linked List
    {
        cout<< " Linked List is Circular in Nature"<<endl;
    }
    else{
        cout<< " Linked List is Circular in Nature"<<endl;
    }
    return 0;
}
*/