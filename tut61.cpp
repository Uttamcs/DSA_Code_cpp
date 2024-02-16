
/*
// Queue reversal

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q)
    {
        stack<int>st;
        while(!q.empty())
        {
            int element = q.front();
            q.pop();
            st.push(element);
        }
        while(!st.empty())
        {
            int element = st.top();
            st.pop();
            q.push(element);
        }
        return q;
    }
int main()
{
    // code to taking input in queue
    queue<int> q;
    int n, var;
    cin>>n;
    while(n--)
    {
        cin>>var;
        q.push(var);
    }
    // function calling
    q = rev(q);
    // queue printing
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
*/















/*
// First negative integer in every window of size k

#include<bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeNumber(long long int A[],long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    // process for the very first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // store answer of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for all remaining windows
    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // ans store
        if(dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    int n = 5;
    int k = 2;
    long long int arr[n] = {-8,2,3,-6,10};
    vector<long long > ans = printFirstNegativeNumber(arr, n, k);
    for (int i = 0; i < n-1; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
*/















/*
// Reverse first K elements of Queue

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int>& q, int k)
{
    // step 1  : pop first k from q and put into stack
    stack<int>s;

    for (int i = 0; i < k; i++)
    {
        int val  = q.front();
        q.pop();
        s.push(val);
    }

    // step 2 : fetch from stack and push into q
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step 3: fetch first (n-k) element from q and push back

    int t = q.size() - k;

    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int> qt = modifyQueue(q, 3);
    while (!qt.empty())
    {
        cout<<qt.front()<<" ";
        qt.pop();
    }
    return 0;
}
*/











/*

// First non- repeating character in a stream

#include<bits\stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.size(); i++)
    {
        char ch = A[i];

        // increase count
        count[ch]++;

        // queue me push kare
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating character
                q.pop();
            }
            else
            {
                // non-repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    string ans = FirstNonRepeating(str);
    cout<<ans<<endl;
    return 0;
}
*/












/*
#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}
int main()
{
    petrolPump p[4] = {{4, 6},{6, 5},{7, 3},{4, 5}};
    int result = tour(p, 4);
    cout << "Result: " << result << endl;
    return 0;
}
*/















/*

// Interleave the First Half of the Queue with Second Half

// Approach - 1  (Using vector)

#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeQueue(queue<int> &q)
{
    queue<int> newq;
    vector<int> ans;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        newq.push(q.front());
        q.pop();
    }
    while (!newq.empty() && !q.empty())
    {
        int val = newq.front();
        newq.pop();
        ans.push_back(val);
        val = q.front();
        q.pop();
        ans.push_back(val);
    }
    return ans;
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(5);
    q.push(6);
    q.push(8);
    q.push(9);
    vector<int> ans = rearrangeQueue(q);
    for(int digit : ans)
    {
        cout<<digit<<" ";
    }
    return 0;
}
*/










/*
// Approach -2 (Using Queue)
#include <bits/stdc++.h>
using namespace std;
queue<int> rearrangeQueue(queue<int> &q)
{
    queue<int> newq;
    vector<int> ans;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        newq.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        int val = newq.front();
        newq.pop();
        newq.push(val);
        val = q.front();
        q.pop();
        newq.push(val);
    }
    return newq;
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(5);
    q.push(6);
    q.push(8);
    q.push(9);
    queue<int> ans = rearrangeQueue(q);
    while (!ans.empty())
    {
        int val  = ans.front();
        cout<<val<< " ";
        ans.pop();
    }

    return 0;
}
*/















/*
// Approach - 3 (using stack)
#include <bits/stdc++.h>
using namespace std;
queue<int> rearrangeQueue(queue<int> &q)
{
    stack<int> st;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        q.push(val);
    }

    for (int i = 0; i < size / 2; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    for (int i = 0; i < size / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        q.push(val);
        val =q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(5);
    q.push(6);
    q.push(8);
    q.push(9);
    queue<int> ans = rearrangeQueue(q);
    while (!ans.empty())
    {
        int val = ans.front();
        ans.pop();
        cout<<val<<" ";
    }
    return 0;
}

*/












/*

#include <bits/stdc++.h>
using namespace std;
class nQueue
{
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freespot;
    int n;
    int k;

public:
    nQueue(int k, int n)
    {
        this->n = n;
        this->k = k;
        front = new int[n];
        rear = new int[n];
        arr = new int[k];
        next = new int[k];

        // Initialize all queues as empty and all slots as free
        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < k; i++)
        {
            next[i] = i + 1;
        }
        next[k - 1] = -1;
        freespot = 0;
    }
    bool isFull()
    {
        return (freespot == -1);
    }
    bool isEmpty(int qn)
    {
        return (front[qn - 1] == -1);
    }
    void enqueue(int x, int qn)
    {
        // Check if the array is full
        if (isFull())
        {
            cout << "Array is full" << endl;
            return;
        }
        // Get the index
        int index = freespot;

        // Update the freespot
        freespot = next[index];

        // If the queue is empty, update both front and rear
        if (isEmpty(qn))
        {
            front[qn - 1] = index;
            rear[qn - 1] = index;
        }
        else
        {
            // Else, update the next of rear and rear
            next[rear[qn - 1]] = index;
        }
        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = x;
    }
    int dequeue(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        // find index to pop
        int index = front[qn - 1];

        // front ko aage baddhao
        front[qn - 1] = next[index];

        // freeslots ko manage karo
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    nQueue kq(10, 3);

    kq.enqueue(10, 1);
    kq.enqueue(15, 1);
    kq.enqueue(20, 2);
    kq.enqueue(25, 1);

    cout << kq.dequeue(1) << endl;
    cout << kq.dequeue(2) << endl;
    cout << kq.dequeue(1) << endl;
    cout << kq.dequeue(1) << endl;
    cout << kq.dequeue(1) << endl;
    return 0;
}
*/













#include <bits/stdc++.h>
using namespace std;
int solve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k size window

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // remaining windows ko process kar lo
    for (int i = k; i < n; i++)
    {
        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition v kar do
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;
    return 0;
}
