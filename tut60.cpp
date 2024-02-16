
/*
// Implementation of Queue

#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int size;
    int rear;
    int qfront;
    int *arr;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        rear = 0;
        qfront = 0;
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
            return false;
    }

    void enqueue(int data)
    {

        if (rear == size)
        {
            cout << "Queue is full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {

        if (rear == qfront)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {

        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    Queue q ;
    q.enqueue(5);
    q.enqueue(52);
    q.enqueue(55);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    return 0;
}
*/









/*
// Implementation of circular Queue
#include <bits/stdc++.h>
using namespace std;
class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int data)
    {
        this->size = data;
        arr = new int[size];
        front = rear = -1;
    }
    bool enqueue(int n)
    {
        // check whether Queue is full or not
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
            return false;
        }
        else if (front == -1)
        {
            // if first element is to push
            front = rear = 0;
            arr[rear] = n;
        }
        else if (rear == size - 1 && front != 0)
        {
            // to maintain cycle
            rear = 0;
            arr[rear] = n;
        }
        else
        {
            // normal flow
            rear++;
            arr[rear] = n;
        }
        return true;
    }
    int dequeue()
    {
        // check whether Queue is empty or not
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        // single element is present
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            // to maintain cycle
            front = 0;
        }
        else
        {
            // normal flow
            front++;
        }
        return ans;
    }
};
int main()
{
    CircularQueue cq(5);
    cq.enqueue(5);
    cq.enqueue(45);
    cq.enqueue(14);
    cq.enqueue(23);
    cq.enqueue(89);
    cq.dequeue();
    cq.enqueue(25);
    cq.enqueue(76);
    return 0;
}
*/













//          DOUBLY QUEUE
#include<bits/stdc++.h>
using namespace std;
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        this-> size =n;
        arr = new int[size];
        rear = front = -1; 
   }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check whether Queue is full or empty
        if ((front == 0 && rear == size -1) || (rear == (front -1)%(size -1)))
        {
            return false;
        }
        else if(front == -1)
        {
            // first element to be pushed
            front = rear =0;
        }
        else if(front == 0 && rear != size -1)
        {
            front = size-1;
        }
        else
        {
            front--;
        }
        arr[front] =x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // check whether Queue is empty or not
        if ((front == 0 && rear == size -1) || (front!= 0 && rear == (front -1)%(size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            // if single element is to be pushed
            front = rear = 0;
        }
        else if((rear == size -1) && (front != 0))
        {
            // to maintain cycle
            rear = 0;
        }
        else
        {
            // normal flow
            rear ++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // check whether Queue is empty or not 
        if(front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            // if single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            // to maintain cycle
            front = 0;
        }
        else
        {
            // normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // check whether Queue is empty or not
        if(rear== -1)
        {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            // if single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        {
            // to maintain cycle
            rear = size - 1;
        }
        else
        {
            // normal flow
            rear -- ;
        }
        return ans;    
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front ==-1 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size - 1)||(front != 0 && rear == (front -1)%(size - 1)))
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};
int main()
{
    Deque dq(2);
    // cout<<dq.pushRear(5)<<endl;
    // dq.pushRear(24);
    // dq.pushRear(25);
    cout<<dq.pushFront(15)<<endl;
    cout<<dq.pushRear(25)<<endl;
    cout<<dq.pushFront(20)<<endl;
    // dq.pushFront(78);
    // cout<<dq.isEmpty()<<endl;
    // cout<<dq.getFront()<<endl;
    cout<<dq.isFull()<<endl;
    cout<<dq.getRear()<<endl;
    // cout<<dq.popFront()<<endl;
    // cout<<dq.getFront()<<endl;
    return 0;
}
