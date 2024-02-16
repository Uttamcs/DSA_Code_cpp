// You are given a special linked List with N nodes where each Node has a next pointer pointing to its next node. 
// You are also given a M random pointers, where you will be given M number of pairs denoting two nodes a and b i.e. a -> arb = b.

// Construct a copy of the given list. The copy should consist of exactly N new nodes, where each node has its value set to the value of its corresponding original node.
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that  the pointers in the original list and copied 
// list represent the same list state.None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
// Return the head of the copied list.


// Question Link : https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

/*

// Approach -1 
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* arb;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        arb = NULL;

    }
};
void insertAtHead(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &head, Node* &tail, int d)
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
            tail = temp;
        }
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
Node *copyList(Node *head)
{
    // step -1: Create a cloneList
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    // Original Node ko cloneNode me copy kar do
    Node* temp = head;
    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }
    // Mapping kar do sir
    unordered_map<Node*, Node*> oldToNewNode;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode !=NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode]= cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    originalNode = head;
    cloneNode = cloneHead;
    
    // CloneNode me random pointer ko link kar do kaam ho gya
    while(originalNode != NULL)
    {
        cloneNode -> arb = oldToNewNode[originalNode -> arb];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    return cloneHead;
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
    cout<<"Printing clone Linked list"<<endl;
    Node* clone = copyList(head);
    print(clone);
    return 0;
}

*/










/*
// Approach - 2
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> random = NULL;
    }
};
void insertAtHead(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void insertAtTail(Node* &head, Node* &tail, int d)
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
            tail = temp;
        }
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
Node* copyList(Node *head)
{
    // step -1: Create a cloneList
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    // Original Node ko cloneNode me copy kar do
    Node* temp = head;
    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    // Step -2: cloneNodes in between original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next ; 
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode =next;
    }

    // step- 3: random pointer copy
    temp = head;
    while (temp != NULL)
    {
        if(temp -> next != NULL){
        temp -> next -> random = temp -> random ? temp -> random -> next: temp -> random ;
        }
        temp = temp -> next -> next;
    }
    // Step- 4: Revert changes done in step 2
    originalNode =head;
    cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode-> next;
        if (originalNode != NULL)
        {
            cloneNode -> next = originalNode -> next ;
        }
        cloneNode = cloneNode -> next;
    }

    // Step -5: return ans
    return cloneHead;
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
    cout<<"Printing clone Linked list"<<endl;
    Node* clone = copyList(head);
    print(clone);
    return 0;
}
*/
