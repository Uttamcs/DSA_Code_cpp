/*
// Next Smaller Element


// Given an array, print the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element 
// on the right side of x in the array. Elements for which no smaller element exist (on the right side), consider NSE as -1. 

#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);

    for(int i= n-1; i>=0 ; i--)
    {
        int curr= arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        ans[i]= s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{
    vector<int>vc={2,1,4,3};
    vector<int>ans = nextSmallerElement(vc,4);
    for (int i = 0; i < 4; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}

*/












/*
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area 
// of the largest rectangle in the histogram.

#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &heights, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        int curr = heights[i];
        while(s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> &heights, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = heights[i];
        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int>next(n);
    next = nextSmallerElement(heights, n);
    
    vector<int>prev(n);
    prev = prevSmallerElement(heights, n);
    
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if(next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(newArea , area);
    }
    return area;
}
int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    cout<<largestRectangleArea(arr)<<endl;
    return 0;
}
*/