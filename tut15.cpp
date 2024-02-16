/*


                                            // // BRUTE FORCE METHOD
// You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ represents the number of pages in the
//  ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to the students.

// Allocate books in a way such that:

// Each student gets at least one book.
// Each book should be allocated to a student.
// Book allocation should be in a contiguous manner.

// You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.


#include <bits/stdc++.h>
using namespace std;

bool isPossible(int pages[], int n, int m, int numPages) {
    int cntStudents = 1;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > numPages) {
            return false;
        }
        if (curSum + pages[i] > numPages) {

            cntStudents += 1;

            curSum = pages[i];

            if (cntStudents > m) {
                return false;
            }
        } else {
            curSum += pages[i];
        }
    }
    return true;
}
int allocateBooks(int pages[], int n, int m) {
    if (n < m) {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }

    for (int numPages = 1; numPages <= sum; numPages++) {
        if (isPossible(pages, n, m, numPages)) {
            return numPages;
        }
    }
    return -1;
}
int main() {
    int n = 4;
    int m = 2;
    int pages[] = {10, 20, 30, 40};
    cout << allocateBooks(pages, n, m) << endl;
}
*/






/*





                                    // //   OPTIMIZE SOLUTION

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int CountStudent = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            CountStudent++;
            if (CountStudent > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
        if (CountStudent > m)
        {
            return false;
        }
    }
    if(m>n){
        return false;
    }
    return true;
}
int allocateBooks(vector<int> arr,int n, int m){
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while (s<=e)
    {
        if (isPossible(arr,n,m, mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int>arr={12,34,67,90};
    cout<<allocateBooks(arr,4,2);
}

*/
















#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
   	int s = 0;
    int n = stalls.size();
    int e=stalls[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}