/*
// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1]. Now, in the given array/list, 'M' numbers
// are present twice and one number is present only once. You need to find and return that number which is unique in the array/list.
#include<iostream>
using namespace std;
int findUnique(int *arr, int size)
{
    int ans=0;
    for(int i=0; i<size; i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[11]={4,5,6,7,8,7,6,5,4,9,8};
    cout<<"Unique element "<<findUnique(arr, 11);
    return 0;
}
*/

/*
// You are given an array 'ARR' of size 'N' containing each number between 1 and 'N' - 1 at least once. There is a single integer value
// that is present in the array twice. Your task is to find the duplicate integer value present in the array. For example:
// Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
// Note: A duplicate number is always present in the given array.
#include <iostream>
using namespace std;
int findDuplicate(int arr[], int size)
{
    int ans = 0;

    // XOR ing all array elements
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    // XOR [1, n-1]

    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
    int arr[5] = {1, 2, 2, 4, 3};
    cout<<findDuplicate(arr, 5)<<endl;;
    return 0;
}
*/


/*
// You have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements in the array/list.
// You don't need to print or return anything, just change in the input array itself.
#include<iostream>
using namespace std;
void printArray(int arr[] , int n);
void swapAlternate(int arr[], int size){
    for (int i = 0; i < size; i+=2)
    {
        if ((i+1)<size){
            swap(arr[i], arr[i+1]);
        }
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
int main(){
    int arr[8]={59,2,65,32,632,26,65,2};
    swapAlternate(arr, 8);
    printArray(arr,8);
    int brr[5]={845,56,65,56,6};
    swapAlternate(brr,5);
    printArray(brr,5);
    return 0;

}
*/

/*

// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order.
// You have to find the intersection of these two arrays. Intersection of two arrays is an array that consists of all the common
// elements occurring in both arrays.
// Note:
// 1. The length of each array is greater than zero.
// 2. Both the arrays are sorted in non-decreasing order.
// 3. The output should be in the order of elements that occur in the original arrays.
// 4. If there is no intersection present then return an empty array.
#include<vector>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while(i<n && j<m) {

    if(arr1[i]==arr2[j])
    {
        ans.push_back(arr1[i]);
        i++;
        j++;
    }
    else if (arr1[i] < arr2[j]) {
        i++;
    }
    else
    {
        j++;
    }

    }
    return ans;
}
*/

/*

// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements
// such that each sum of elements of each pair equals 'S'.
// Note:
//      Each pair should be sorted i.e the first value should be less than or equals to the second value.
//      Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first
//      value, the pair with a smaller second value should come first.

#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > pairSum(vector<int> &arr, int s){
   vector< vector<int> > ans;

   for(int i=0;i<arr.size(); i++ )
   {
        for(int j = i+1; j<arr.size(); j++) {
            if(arr[i] +arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
   }
   sort(ans.begin(), ans.end());
   return ans;
}
*/




/*

// You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
// An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.
// Note:
// 1. You can return the list of values in any order. For example, if a valid triplet is {1, 2, 3}, then {2, -3, 1}, {-3, 2, 1} etc is also valid triplet. Also, the ordering of different triplets can be random i.e if there are more than one valid triplets, you can return them in any order.
// 2. The elements in the array need not be distinct.
// 3. If no such triplet is present in the array, then return an empty list, and the output printed for such a test case will be "-1".

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    vector<vector<int>> result;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {

        int left = i + 1;

        int right = n - 1;

        while (left < right)
        {

            int sum = arr[i] + arr[left] + arr[right];

            if (sum == K)
            {

                result.push_back({arr[i], arr[left], arr[right]});

                left++;

                right--;

                while (left < right && arr[left] == arr[left - 1])
                {

                    left++;
                }

                while (left < right && arr[right] == arr[right + 1])
                {

                    right--;
                }
            }

            else if (sum < K)
            {

                left++;
            }

            else
            {

                right--;
            }
        }

        while (i + 1 < n && arr[i] == arr[i + 1])
        {

            i++;
        }
    }

    return result;
}
*/








// You have been given an integer array of size 'N'. It only contains 0s, 1s, and 2s. Write a solution to sort this array
#include<iostream>
using namespace std;
void printArray(int arr[], int n ){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void sortOne(int arr[], int n){
    int left=0,right=n-1;
    while (left< right)
    {
        while (arr[left]==0 && left<right)
        {
            left++;
        }
        while (arr[right]==1 && left<right)
        {
            right--;
        }
        if (left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}
    int main(){
        int arr[8]={1,1,0,0,1,0,1,0};
        sortOne(arr,8);
        printArray(arr,8);
        return 0;
    }