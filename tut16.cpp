#include <vector>
#include<iostream>
using namespace std;
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
            swap(arr[minIndex], arr[i]);
    }
}
int main()
{
    vector<int> arr={1,5,8,58,8,65,59,484};
    selectionSort(arr,8);
    for (int i = 0; i < 8; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}