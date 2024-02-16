/*
// You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer ‘K’.
// Now, your task is to find the first and last occurrence of ‘K’ in ARR.
// Note :
// 1. If ‘K’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. ARR may contain duplicate elements.
// For example, if ARR = [0, 1, 1, 5] and K = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

#include<bits/stdc++.h> 
#include<vector>
using namespace std;
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid=(s+e)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {
            s = mid + 1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }

        mid = (s+e)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid=(s+e)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {
            s = mid + 1;
        }
        else if(key < arr[mid]) {
            e = mid - 1;
        }

        mid = (s+e)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int key)
{
    pair<int,int>v;
    v.first=firstOcc(arr, n, key);
    v.second=lastOcc(arr, n, key);
    return v;
}
*/












// An array is said to be a mountain array if it satisfies the following conditions:
// The length of the given array is should be greater or equal to 3 i.e. LENGTH >=3.
// There must be only one peak in the array or the largest element in the array.
// The array must follows the condition: ARRAY[0] < ARRAY[1] < ARRAY[i-1] < ARRAY[ i] > ARRAY[ i+1 ] > ARRAY[..] > ARRAY[length-1]
// The task is to find the peak index of the mountain array.
// Suppose we have given the input [60, 20, 90, 110, 10].
// The output will be 3. Because the largest element in the array is 110 whose index is 3.


/*
#include <bits/stdc++.h>
#include <array>
using namespace std; 
int main()
{
    int arr[10] = {1, 2, 5, 6, 7, 8, 4, 3, 2, 1};
    int left = 0;
    int right = 9;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    cout << left;
}

*/








