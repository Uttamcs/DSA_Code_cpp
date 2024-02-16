/*
// Check given array is sorted or not with the help of recursion
#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}
int main()
{
    int arr[5] = {1, 3, 4, 5, 6};
    int size = 5;
    int ans = isSorted(arr, size);
    if (ans)
    {
        cout << "Array is sorted " << endl;
    }
    else
    {
        cout << "Array is not sorted " << endl;
    }
    return 0;
}
*/





/*
#include<iostream>
using namespace std;
int getSum(int arr[], int size)
{
    int sum=0;
    if(size==0){
        return 0;
    }
    int remainingSum=arr[size-1]+getSum(arr, size-1);
    return remainingSum;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int size=5;
    cout<<getSum(arr, size)<<endl;
    return 0;
}
*/





/*
#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[], int size, int key)
{
    if(size==0)
    {
        return false;
    }
    if(arr[0]==key)
    {
        return true;
    }
    else
    {
        return linearSearch(arr+1, size-1, key);
    }
}
int main()
{
    int arr[5]={1,2,6,8,9};
    int size=5;
    int key=9;
    int ans=linearSearch(arr, size, key);
    if (ans)
    {
        cout<<key<<" is found in array"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}
*/




/*


// Binary Search using Recursion
#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int *arr, int key, int start, int end)
{
    if(start>end){
        return false;
    }
    
    int mid=start+(end-start)/2;
    if (arr[mid]==key)
    {
        return true;
    }
    else if ((start==end) &&(arr[mid]!=key))
    {
        return false;
    }
    
    
    if (arr[mid]>key)
    {
        return binarySearch(arr,key,start,mid-1);
    }
    else
    {
        return binarySearch(arr,key,mid+1,end);
    }
}
int main()
{
    int arr[6]={1,3,4,6,8,9};
    int key =666;
    int start=0;
    int end=5;
    int ans=binarySearch(arr, key, start, end);
    cout<<ans<<endl;
    return 0;
}
*/











