#include<bits/stdc++.h>
using namespace std;
class nStack{
    int *arr;
    int *top;
    int *next;
    int n , s;

    int freespot;

    public:
    nStack(int N, int S)
    {
        n=N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise 
        for(int i=0 ; i<n; i++){
            top[i] = -1;
        }

        // next initialise
        for(int i=0 ;i<s; i++)
        {
            next[i] = i+1;
        }

        // update the last index value to -1
        next[s-1] = -1;

        // initialise freespot
        freespot = 0;
    }
    bool push(int x, int m)
    {
        // check for overflow
        if(freespot == -1)
        {
            return false;
        }
        // find index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next;
        next[index] = top[m-1];                       // m-1 because here 0 based index is occuring

        // update top 
        top[m-1] = index;

        return true;
    }

    int pop(int m)
    {
        // check underflow condition
        if (top[m-1] == -1)
        {
            return -1;
        }

        int index = top[m-1];
        top[m-1] = index;
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{
    int n = 3, s=9;
    nStack n1 = nStack(n,s);
    n1.push(49,1);
    n1.push(52,3);
    n1.push(24,3);
    cout<<n1.pop(1)<<endl;
    cout<<n1.pop(3)<<endl;
    // cout<<n1.pop(3)<<endl;
    return 0;
}