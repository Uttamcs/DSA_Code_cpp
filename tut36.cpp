/*

//              QUICK SORT
#include<iostream>
using namespace std;
int partition(int arr[], int s, int e )
{
    int pivot=arr[s];

    int count=0;
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i]<=pivot)
        {
            count++;
        }
    }
    // place pivot at right place 
    int pivotIndex=s+count;
    swap(arr[s], arr[pivotIndex]);

    int i=s;
    int j=e;
    while (i< pivotIndex && j> pivotIndex)
    {
        while (arr[i]<pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if (i< pivotIndex && j>pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    // base case
    if (s>=e)
    return ;

    // partition karenge
    int p=partition(arr, s, e);

    // left part ko sambhal lete hai
    quickSort(arr, s, p-1 );

    // right part ko sambhal lete hai
    quickSort(arr, p+1, e);
    
}
int main()
{
    int arr[10]={15,51,59,5,56,0,5,18,9,523};
    int size=10;
    cout<<"Before sorting array is like this:-"<<endl<<endl<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    quickSort(arr, 0, size-1);

    cout<<"After sorting array is like this:-"<<endl<<endl<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}


*/
