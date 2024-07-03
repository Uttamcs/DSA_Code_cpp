// Find index of a target element by binary search algorithm


/*
// Method - 1

#include <bits/stdc++.h>
using namespace std;

int bs(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 3, 4, 6, 7, 8, 9, 11, 22, 41};
    int target = 4;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << bs(arr, size, target) << endl;
}
*/



/*******************************************************************************************************/





// Method - 2
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bs(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return bs(arr, low, mid - 1, target);
    }
    return bs(arr, mid + 1, high, target);
}
int main()
{
    int arr[10] = {1, 3, 4, 6, 7, 8, 9, 11, 22, 41};
    int target = 4;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << bs(arr, 0, size - 1, target) << endl;
}