
/*
// To find is there any loop present in Linked List or not

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
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout<<"Present on element "<<temp->data<<endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
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
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);

    InsertAtTail(tail, 45);
    InsertAtTail(tail, 51);
    inserAtPos(head, tail, 4, 555);
    inserAtPos(head, tail, 1, 121);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    tail-> next= head-> next;
    if (detectLoop(head))
    {
        cout << "Yes, there is a loop in the Linked List" << endl;
    }
    else
    {
        cout << "No, there isn't a loop in the Linked List" << endl;
    }
    return 0;
}
*/






/*

//                          floydDetectLoop

// To find is there any loop present in Linked List or not if present then find the starting point of the loop

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
Node* floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            // cout << "Present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow= head;
    while (slow != intersection)
    {
        slow=slow->next;
        intersection=intersection -> next;
    }
    return slow;
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
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    InsertAtTail(tail, 45);
    InsertAtTail(tail, 51);
    inserAtPos(head, tail, 4, 555);
    inserAtPos(head, tail, 1, 121);
    print(head);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    tail->next = head->next;
    if (floydDetectLoop(head))
    {
        cout << "Yes, there is a loop in the Linked List" << endl;
        cout<<"Starting Point "<<getStartingNode(head)->data<<endl;
    }
    else
    {
        cout << "No, there isn't a loop in the Linked List" << endl;
    }
    return 0;
}
*/













/*

// Remove cycle from Linked List


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
Node* floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            // cout << "Present at " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    Node* slow= head;
    while (slow != intersection)
    {
        slow=slow->next;
        intersection=intersection -> next;
    }
    return slow;
}
void removeLoop(Node* &head)
{
    if (head == NULL)
    {
        cout<<"Empty list"<<endl;
        return ;
    }
    Node* startofLoop = getStartingNode(head);
    // Remove loop
    Node* temp= startofLoop;
    while (temp -> next != startofLoop)
    {
        temp = temp -> next;
    }
    temp -> next= NULL;
}
void isLoop(Node* head)
{
    if (floydDetectLoop(head))
    {
        cout << "Yes, there is a loop in the Linked List" << endl;
        cout<<"Starting Point "<<getStartingNode(head)->data<<endl;
    }
    else
    {
        cout << "No, there isn't a loop in the Linked List" << endl;
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
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    tail->next = head->next;
    isLoop(head);
    removeLoop(head);
    cout<<"After deleting loop"<<endl;
    isLoop(head);
    print(head);
    return 0;
}
*/
