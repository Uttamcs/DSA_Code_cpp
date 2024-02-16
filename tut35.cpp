/*
// Merge sort using recursion
#include<iostream>
using namespace std;
void merge(int arr[], int s, int e)
{
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    // copy values
    int mainArrayIndex=s;
    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex=mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i]=arr[mainArrayIndex++];
    }
    
    // merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=s;

    while (index1<len1 && index2<len2){
        if (first[index1]<second[index2])
        {
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }
    while (index1<len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }
    while (index2<len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }
    delete [] first;
    delete [] second;
}
void mergeSort(int arr[], int s, int e)
{
    if(s>=e) 
    return ;
    int mid=(s+e)/2;
    mergeSort(arr,s ,mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s ,e);
}
int main()
{
    int arr[15]={1,54,5,8,56,9,45,517,9,152,51,54,1,511,485};
    int size=15;

    cout<<"Before sorting array is like this:-"<<endl<<endl<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    mergeSort(arr, 0, size-1);

    cout<<"After sorting array is like this:-"<<endl<<endl<<endl;
    for (int i = 0; i < 15; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
*/