// // Implementation of Heap

// // Heap is a data structure which is a CBT(complete binary tree) that comes with a heap order property
// // A CBT is a binary tree in which all the levels are completely filled except the last level nodes always added from the left in CBT or lean towards the left

// // max heap --> parent is always greater than childs
// // min heap --> parent is always smaller than childs

// // node -> ith index(For 1- based indexing);
// // left child -> 2*i index
// // right child -> (2*i + 1) index
// // parent  -> (i/2) index

// // node -> ith index(For 0- based indexing);
// // left child -> 2*i +1 index
// // right child -> (2*i + 2) index
// // parent  -> (i/2) index

// #include <iostream>
// using namespace std;
// class heap
// {
// public:
//     int arr[100];
//     int size;

//     heap()
//     {
//         arr[0] = -1;
//         size = 0;
//     }

//     void insert(int val)
//     {
//         size++;
//         int idx = size;
//         arr[size] = val;

//         while (idx > 1)
//         {
//             int parent = idx / 2;
//             if (arr[parent] < arr[idx])
//             {
//                 swap(arr[parent], arr[idx]);
//                 idx = parent;
//             }
//             else
//             {
//                 return;
//             }
//         }
//     }
//     void print()
//     {
//         for (int i = 1; i <= size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     void deleteFromHeap()
//     {
//         if (size == 0)
//         {
//             cout << "Nothing to delete" << endl;
//             return;
//         }

//         // Step 1: Put last element into the first Index
//         arr[1] = arr[size];
//         // Step 2: remove last element
//         size--;
//         // Step 3: take root to its correct position
//         int i = 1;
//         while (i < size)
//         {
//             int leftIdx = 2 * i;
//             int rightIdx = 2 * i + 1;

//             if (leftIdx < size && arr[i] < arr[leftIdx])
//             {
//                 swap(arr[i], arr[leftIdx]);
//                 i = leftIdx;
//             }
//             else if (rightIdx < size && arr[i] < arr[rightIdx])
//             {
//                 swap(arr[i], arr[rightIdx]);
//                 i = rightIdx;
//             }
//             else
//             {
//                 return;
//             }
//         }
//     }
// };


// void heapify(int arr[], int n, int i)
// {
//     int largest = i;
//     int left = 2 * i;
//     int right = 2 * i + 1;

//     if (left <= n && arr[largest] < arr[left])
//     {
//         largest = left;
//     }
//     if (right <= n && arr[largest] < arr[right])
//     {
//         largest = right;
//     }

//     // largest update ho gya hoga to i equal nahi hoga
//     if (largest != i)
//     {
//         swap(arr[largest], arr[i]);
//         heapify(arr, n, largest);
//     }
// }

// int main()
// {
//     heap hp;
//     hp.insert(5);
//     hp.insert(41);
//     hp.insert(88);
//     hp.insert(54);
//     hp.insert(53);
//     hp.insert(50);
//     hp.insert(52);
//     hp.print();

//     cout << "After deleting from Heap" << endl;
//     hp.deleteFromHeap();
//     hp.print();

//     int arr[6] = {-1, 54, 53, 55, 52, 50};
//     int n = 5;

//     for(int i = n/2; i >= 0; i--)
//     {
//         heapify(arr, n, i);
//     }
//     cout<<"Printing the array now"<<endl;
//     for(int i = 1; i<= n ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }








// // Build Min heap from array
// #include<bits/stdc++.h>
// using namespace std;
// void heapify(int arr[], int n , int i)
// {
//     int smallest = i;
//     int left = 2*i + 1;
//     int right = 2*i + 2;

//     if(left <n && arr[smallest] > arr[left])
//     {
//         smallest = left;
//     }
//     if(right <n && arr[smallest] > arr[right])
//     {
//         smallest = right;
//     }
//     if(smallest != i)
//     {
//         swap(arr[smallest], arr[i]);
//         heapify(arr, n, smallest);
//     }
// }
// int main()
// {
//     int arr[] = {9 ,3 ,2 ,6 ,7 };
//     int n = 5;
//     for(int i = n/2; i>= 0; i--)
//     {
//         heapify(arr, n, i);
//     }
//     for(auto it:arr)
//     {
//         cout<<it<<" ";
//     }
//     cout<<endl;
// }















// Heap Sort 
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n , int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left <n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if(right <n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if(smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // Step -1 : Swap 
        swap(arr[size], arr[1]);
        //Step 2
        size--;
        //Step 3 
        heapify(arr, n, 1);
    }
}
int main()
{
    int arr[6] = {-1, 54,53,55,52,50};
    int n = 5;
    heapSort(arr, n);
    for (size_t i = 1; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}