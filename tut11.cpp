//                   Pair datatype

/*
#include<iostream>
using namespace std;
int main(){
    pair<int, int> p;
    p={1, 5};
    cout<<p.first<<" "<<p.second;
    return 0;
}
*/

/*
//  We can also make a array of pair datatype
#include<iostream>
using namespace std;
int main(){
    pair<int, int> arr[]={{3,1},{8,9},{5,9}};
    // Or we can also initialize array by this method
    // pair<int, int> arr[3];
    // arr[0]={5,4};
    // arr[1]={9,7};
    // arr[2]={5,6};
    for (int i = 0; i < 3; i++)
    {
        cout<<"("<<arr[i].first <<","<<arr[i].second<<")"<<endl;
    }
    return 0;
}
*/



/*
//                      Vectors & List & Deque

//  List and deque have only one extra feature than vector it has push_front and emplace_front function
//  list<int>li;            --> Syntax to make a list
//  deque<int>dq;            --> Syntax to make a deque
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9); 
    v.emplace_back(2);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    // Copying array into another
    vector<int> v1(v);
    v1.push_back(45);
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl << endl;
    vector<pair<int, int>> vec;
    vec.push_back({5, 9});
    vec.emplace_back(4, 7);
    cout << vec.at(0).first << " " << vec.at(0).second << " " << vec.at(1).first << " " << vec.at(1).second << " ";

    cout << endl << endl;
    vector<int> v2(5,100);
    for(auto i:v2){
        cout<<i<<" ";
    }

    cout << endl << endl;
    vector<int> v3(7);
    for(auto i:v3){
        cout<<i<<" ";
    }

    cout << endl << endl;
    cout<<"After erasing element of postion 2 from array v"<<endl;
    v.erase(v.begin()+1);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl << endl;


    // If we want to erase a series of elements then 
    cout<<"After erasing a series of element from array v"<<endl;
    v.erase(v.begin(), v.begin()+2);
    for(auto i:v){
        cout<< i<<" ";
    }
    cout << endl << endl;

    // What if want to insert element in vector
    v.insert(v.begin()+1,421);
    for(auto i:v){
        cout<< i<<" ";
    }
    cout << endl << endl;

    // What if want to insert a element multiple times in vector
    v.insert(v.begin()+1,5,11);
    for(auto i:v){
        cout<< i<<" ";
    }
    cout << endl << endl;

    vector<int> copy(2,50);
    for(auto i:copy){
        cout<<i<<" ";
    }
    cout << endl << endl;
    cout<<"Inserting an array "<<endl;
    v.insert(v.begin(),copy.begin(), copy.end());
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"Size of vector v is "<<v.size()<<endl;
    cout<<endl<<"After pop_back"<<endl<<endl;
    v.pop_back();
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"Before swapping v2"<<endl;
    for(auto i:v2){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    cout<<"Before swapping v3"<<endl;
    for(auto i:v3){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    // Swaps elements of one vector to another vector
    v2.swap(v3);
    cout<<"After swapping v2"<<endl;
    for(auto i:v2){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    cout<<"After swapping v3"<<endl;
    for(auto i:v3){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    //  Clear each and every element of a vector
    v2.clear();
    cout<<"After clearing vector v2"<<endl;
    for(auto i:v2){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    // Empty return us 0 or 1 
    // if vector is empty -->it returns 1
    // if vector is non empty -->it returns 0
    cout<<"Empty : "<<v2.empty()<<endl;
    return 0;
}
*/





/*
//                  Stack-->LIFO(Last In First Out)
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>sk;
    sk.push(1);     //{1}
    sk.push(2);     //{2,1}
    sk.push(3);     //{3,2,1}
    sk.push(4);     //{4,3,2,1}
    sk.push(4);     //{4,4,3,2,1}
    sk.push(6);     //{6,4,4,3,2,1}
    sk.push(8);     //{8,6,4,4,3,2,1}

    cout<<"Top in stack sk:"<<sk.top()<<endl;
    cout<<"Size of stack sk:"<<sk.size()<<endl;
    sk.pop();
    cout<<endl;
    cout<<"After pop"<<endl;
    cout<<"Top in stack sk:"<<sk.top()<<endl;
    cout<<"Size of stack sk:"<<sk.size()<<endl;
    cout<<"Empty: "<<sk.empty();
    stack<int>st;
    st.swap(sk);
    return 0;
}
*/






/*
//                Queue -->FIFO (First In First Out)
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    q.push(5);          //{5}
    q.push(6);          //{5,6}
    q.push(7);          //{5,6,7}
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    q.back()+=3;
    cout<<"After adding in back"<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    q.pop();
    cout<<"After pop"<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Back: "<<q.back()<<endl;
    return 0;
}
*/






/*

//              Priority Queue--> Highest number will be on top
 
#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    pq.push(5);         //{5}
    pq.push(845);       //{5,845}
    pq.push(51);        //{5, 845, 51}
    pq.push(541);       //{5, 845, 51, 541}
    cout<<"Prority Queue pq"<<endl<<endl;
    cout<<"Top of queue pq : "<<pq.top()<<endl;
    pq.pop();
    cout<<"After pop"<<endl;
    cout<<"Top of queue pq : "<<pq.top()<<endl;
    priority_queue<int>abc;
    abc.push(5162);
    abc.push(8745);
    cout<<endl<<endl<<"Prority Queue abc"<<endl;
    cout<<"Top of queue abc : "<<abc.top()<<endl;
    abc.swap(pq);
    cout<<"Top of queue pq : "<<pq.top()<<endl;
    cout<<"Top of queue abc : "<<abc.top()<<endl;
    cout<<endl;

    //  What if we want to make minimum heap
    priority_queue<int, vector<int>, greater<int>>pqr;
    cout<<"Minimum Heap"<<endl;
    pqr.push(5);
    pqr.push(845);  
    pqr.push(51);   
    pqr.push(541);     
    cout<<"Top of queue pqr : "<<pqr.top()<<endl;
    pqr.pop();
    cout<<"After pop"<<endl;
    cout<<"Top of queue pqr : "<<pqr.top()<<endl;

    return 0;
}
*/



/*
//          Sets--> Stores everything in sorted and unique
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>st;
    st.insert(1);
    st.insert(5);
    st.insert(9);
    st.insert(5);
    st.insert(2);
    for(auto &it:st){
        cout<<it<<" ";
    }
    cout<<endl;
    // If we want to change sorting order
    set<int, greater<int>>st1;         //-->Syntax
    st1.insert(1);
    st1.insert(5);
    st1.insert(9);
    st1.insert(5);
    st1.insert(2);
    for(auto _it:st1){
        cout<<_it<<" ";
    }
    cout<<endl<<"After erasing"<<endl;
    st1.erase(st1.find(9));
    st1.insert(2);
    for(auto _it:st1){
        cout<<_it<<" ";
    }
    cout<<endl;
    st.erase(st.find(1), st.find(5));
    for(auto &it:st){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<st1.count(5);         //--> It returns 0 and 1 if present then returns 1 otherwise 0
    return 0;
}
*/





/*

//                  MultiSet --> Stores everything in sorted order multiple times unlike set
#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int>ms;
    ms.insert(1);               //{1}
    ms.insert(1);               //{1,1}
    ms.insert(1);               //{1,1,1}   
    ms.insert(1);               //{1,1,1,1}   
    ms.insert(1);               //{1,1,1,1,1}   
    for(auto it:ms){
        cout<<it<<" ";
    }
    cout<<endl;
    ms.erase(ms.find(1));
    for(auto it:ms){
        cout<<it<<" ";
    }
    cout<<endl;
    ms.insert(2);               //{1,1,1,1,2}   
    for(auto it:ms){
        cout<<it<<" ";
    }
    cout<<endl;
    ms.erase(ms.find(1), ms.find(1));
    for(auto it:ms){
        cout<<it<<" ";
    }
    return 0;
}
*/





/*
//                  Algorithm

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6-->"<<binary_search(v.begin(), v.end(),6)<<endl; 

    cout<<"Lower Bound-->"<<lower_bound(v.begin(), v.end(),6)-v.begin()<<endl;
    cout<<"Upper Bound-->"<<upper_bound(v.begin(), v.end(),6)-v.begin()<<endl;
    
    int a=5;
    int b=10;
    cout<<"Max:"<<max(a,b)<<endl;
    cout<<"Min:"<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;


    string abcd="abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"String--> "<<abcd<<endl;

    rotate(v.begin(), v.begin()+1, v.end());
    cout<<"After rotate:"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    sort(v.begin(), v.end());
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
*/