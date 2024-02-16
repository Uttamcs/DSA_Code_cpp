/*

//          The Celebrity Problem

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.


#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int> >& M, int a, int b, int n)
{
    if(M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& M, int n)
{
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        s.push(i);
    }
    while(s.size()>1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b,n)){
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    // row check
    int zeroCount = 0;
    for(int i= 0; i<n; i++)
    {
        if(M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    if(zeroCount != n)
    {
        return -1;
    }
    // col check
    int oneCount = 0;
    for(int i=0 ; i<n; i++)
    {
        if(M[i][ans] == 1)
        {
            oneCount++;
        }
    }
    if(oneCount != n-1)
    {
        return -1;
    }
    return ans;
}
int main()
{
    vector<vector<int>> vc= {{0,1,0},{0,0,0},{0,1,0}};
    int n = vc.size();
    cout<<celebrity(vc, n)<<endl;
    return 0;
}
*/



















//      Max Rectangle

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangularArea(int *arr, int n)
{
    vector<int> next(n);
    next = nextSmallerElement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int maxArea(int M[MAX][MAX], int n, int m)
{
     // compute area for the first row
    int area = largestRectangularArea(M[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // row update karo by adding previous row values
            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];
            else
                M[i][j] = 0;
        }
        // entire row is updated
        area = max(area, largestRectangularArea(M[i], m));
    }
    return area;
}
int main()
{
    int m = 4, n = 4;
    int arr[MAX][MAX] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout << maxArea(arr , n ,m) << endl;
    return 0;
}
// This code is not working in VS Code but it runs in online compiler