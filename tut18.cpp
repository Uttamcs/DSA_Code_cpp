#include <bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int>&arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp=arr[i];
        int j = i-1;
        for (; j >=0; j--)
        {
            if (arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
}

void print(vector<int> arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int> arr={5,52,5,62,2,5,65,32};
    InsertionSort(arr,arr.size());
    print(arr,arr.size());
    return 0;
}