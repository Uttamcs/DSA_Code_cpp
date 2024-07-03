// find index of Upper bound in Sorted Array


/*
// Method - 1 (Brute force method --> linear search algorithm)

#include<bits/stdc++.h> 
using namespace std;
#define ll long long
int ub(vector<ll>arr, int target)
{
    for(int i =0; i<arr.size(); i++)
    {
        if(arr[i] > target)
        {
            return i;
        }
    }
    return arr.size();
}
int main()
{
    vector<ll> vc = {1,2,3,4,7,60,75,100,152,562,985};
    int n= vc.size();
    cout<<ub(vc, 61)<<endl;
    return 0;
}

// time complexity: O(n)

*/






/*


// optimise this code to O(log(n))

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int ub(vector<ll>vc, int target)
{
    int low = 0 , high = vc.size()-1;
    int ans = vc.size();
    while(low <= high)
    {
        int mid = low+(high - low)/2;
        if(vc[mid] >= target)
        {
            ans = mid ;
            high = mid -1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<ll> vc = {1,2,3,4,7,60,75,100,152,562,985};
    int n= vc.size();
    cout<<ub(vc, 61)<<endl;
    return 0;
}


In C++ there is predefined upper_bound function which returns the index of lower bound element



#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    vector<ll> vc = {1,2,3,4,7,60,75,100,152,562,985};
    cout<<upper_bound(vc.begin(), vc.end(),61)- vc.begin()<<endl;
    return 0;
}



*/
