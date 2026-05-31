// // Implement Stack using array 


// #include <bits/stdc++.h>
// using namespace std;
// class Stack{
//     public:
//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }
//     void push(int element){
//         if(size-top>1){
//             top++;
//             arr[top] = element;
//         }
//         else{
//             cout<<"Stack Overflow"<<endl;
//         }
//     }
//     void pop(){
//         if(top >= 0){
//             top--;
//             cout<<"Element popped"<<endl;
//         }else{
//             cout<<"Stack Underflow"<<endl;
//         }
//     }
//     int peek(){
//         if(top >= 0){
//             return arr[top];
//         }else{
//             cout<<"Stack is empty"<<endl;
//             return -1;
//         }
//     }
//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     int getsize(){
//         return top+1;
//     }
//     void print(){
//         for(int i = 0; i <= top; i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };
// int main()
// {
//     Stack st(5);
//     st.push(22);
//     st.push(43);
//     st.push(44);
//     cout<<st.peek()<<endl;
//     st.pop();
//     cout<<st.peek()<<endl;
//     cout<<st.isEmpty()<<endl;
//     cout<<st.getsize()<<endl;
//     return 0;
// }











// // Implement queue using array
// #include <bits/stdc++.h>
// using namespace std;
// class Queue{
//     public:
//     int *arr;
//     int start;
//     int end;

//     Queue(int size){
//         arr = new int[size];
//         start = -1;
//         end = -1;
//     }
//     void push(int element){
//         if(start == -1){
//             start = 0;
//             end = 0;
//             arr[end] = element;
//         }
//         else{
//             end++;
//             arr[end] = element;
//         }
//     }
//     void pop(){
//         if(start == -1){
//             cout<<"Queue is empty"<<endl;
//         }
//         else{
//             start++;
//         }
//     }
//     int peek(){
//         if(start == -1){
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }
//         else{
//             return arr[start];
//         }
//     }
//     bool isEmpty(){
//         if(start == -1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     int getsize(){
//         return end-start+1;
//     }
//     void print(){
//         for(int i = start; i <= end; i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };
// int main()
// {
//     Queue q(5);
//     q.push(22);
//     q.push(43);
//     q.push(44);
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     cout<<q.isEmpty()<<endl;
//     cout<<q.getsize()<<endl;
//     q.print();
//     q.pop();
// return 0;
// }









// // Stack using Linkedlist

// #include <bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//         int data;
//         Node *next;
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }
// };
// class Stack{
//     public:
//         Node *start;
//         Node * end;
//         int size;
//         Stack(){
//             start = NULL;
//             end = NULL;
//             size = 0;
//         }

//         void push(int element){
//             Node *temp = new Node(element);
//             if(start == NULL){
//                 start = temp;
//                 end = temp;
//             }
//             else{
//                 temp->next = start;
//                 start = temp;
//             }
//             size++;
//         }

//         void pop(){
//             if(start == NULL){
//                 cout<<"Stack is empty"<<endl;
//             }
//             else{
//                 Node *temp = start;
//                 start = start->next;
//                 delete temp;
//                 size--;
//             }
//         }

//         int peek(){
//             if(start == NULL){
//                 cout<<"Stack is empty"<<endl;
//                 return -1;
//             }
//             else{
//                 return start->data;
//             }
//         }
//         bool isEmpty(){
//             return start == NULL;
//         }
//         int getsize(){
//             return size;
//         }
// };
// int main()
// {
//     Stack st;
//     st.push(22);
//     st.push(43);
//     st.push(44);
//     cout<<st.peek()<<endl;
//     st.pop();
//     cout<<st.peek()<<endl;
//     st.pop();
//     cout<<st.isEmpty()<<endl;
//     cout<<st.getsize()<<endl;
//     return 0;
// }








// // Implement Stack using Queue

// #include <bits/stdc++.h>
// using namespace std;
// class Stack{
//     public:
//         queue<int> q;
//     void push(int element){
//         int s = q.size();
//         q.push(element);
//         for(int i = 0; i < s; i++){
//             q.push(q.front());
//             q.pop();
//         }
//     }
//     void pop(){
//         if(q.empty()){
//             cout<<"Stack is empty"<<endl;
//         }
//         else{
//             q.pop();
//         }
//     }
//     int peek(){
//         if(q.empty()){
//             cout<<"Stack is empty"<<endl;
//             return -1;
//         }
//         else{
//             return q.front();
//         }
//     }
//     bool isEmpty(){
//         return q.empty();
//     }
//     int getsize(){
//         return q.size();
//     }
// };
// int main()
// {
//     Stack st;
//     st.push(22);
//     st.push(43);
//     st.push(44);
//     cout<<st.peek()<<endl;
//     st.pop();
//     cout<<st.peek()<<endl;
//     st.pop();
//     cout<<st.isEmpty()<<endl;
//     cout<<st.getsize()<<endl;
//     return 0;
// }








// Implement Queue using Stack

#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
        stack<int> s1;
        stack<int> s2;
    void push(int element){
        s1.push(element);
    }
    void pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    int peek(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int ans = s2.top();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return ans;
        }
    }
    bool isEmpty(){
        return s1.empty();
    }
    int getsize(){
        return s1.size();
    }
};
int main()
{
    Queue q;
    q.push(22);
    q.push(43);
    q.push(44);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.isEmpty()<<endl;
    cout<<q.getsize()<<endl;
    return 0;
}