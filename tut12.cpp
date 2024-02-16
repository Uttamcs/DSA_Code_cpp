//              BINARY SEARCH IN AN ARRAY

#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start-(end-start)/2;                      //(start+end)/2 --> is not written bcoz it may be possible when start+end becomes value out of rnage of integer
    while (start <= end)
    {
        if (arr[mid] == key)
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
        mid = start-(end-start)/2;                      //(start+end)/2 --> is not written bcoz it may be possible when start+end becomes value out of rnage of integer
    }
    return -1;
}
int main()
{
    int even[8] = {5, 5, 2, 62, 2, 623, 6, 5};
    int evenIndex = binarySearch(even, 8, 623);
    cout << "Index of 623 is " << evenIndex << endl;
    return 0;
}