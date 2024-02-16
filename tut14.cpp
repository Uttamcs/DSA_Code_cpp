/*
//Find index of Pivot element
#include<bits/stdc++.h>
using namespace std;
int getPivot(int arr[], int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while (s<e)
    {
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else
        {
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main(){
    int arr[8]={25,28,29,1,3,8,10,845};
    cout<<"Pivot is "<<getPivot(arr,5)<<endl;
    return 0;
}
*/

/*
// Search in an rotated array
#include <bits/stdc++.h>
using namespace std;
int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int binarySearch(int arr[], int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (key==arr[mid])
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}


int findPosition(int arr[], int n, int k){
    int pivot=getPivot(arr,n);
    if (k>arr[pivot] && k<arr[n-1])
    {
        return binarySearch(arr,pivot, n-1,k);
    }
    else{
        return binarySearch(arr,0,pivot-1,k);
    }

}
int main()
{
    int arr[8]={15,17,19,21,1,2,3,4};
    cout<<"Index is "<<findPosition(arr,8,19);
    return 0;
}
*/
















/*
// Write a find a program to return square root of a number upto 3 digits precision.(Time Complexity should be log(n))
#include <bits/stdc++.h>
using namespace std;
int sqrtInteger(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double more_precision(int n, int precision, int tempsol)
{
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j*j < n; j+= factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    int tempsol = sqrtInteger(n);
    cout << "Answer is " << more_precision(n, 3, tempsol);
    return 0;
}
*/








