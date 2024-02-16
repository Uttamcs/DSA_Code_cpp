// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

/*


#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k){
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i+k)%nums.size()]=nums[i];
    }
    nums=temp;
}
void print(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v={54,2,5,1,87,956};
    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    cout<<"Original Array"<<endl;
    print(v);
    rotate(v,k);
    cout<<"Rotated Array"<<endl;
    print(v);
    return 0;
}

*/






// Check if array is Sorted and Rotated
/*
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &nums)
{
    int count = 0, n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}
int main()
{
    vector<int> v = {3, 4, 5, 1, 2};
    if(check(v)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}
*/













/*

You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

Note:

1. The length of each array is greater than zero.

2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.

*/



#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int>&arr)
{
	int n = arr.size();
	int s = 0;
	int e = n-1;
	while(s < e)
	{
		swap(arr[s++], arr[e--]);
	}
	return arr;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
	int j = m-1;
	vector<int> ans;
	int carry = 0;

	while(i >= 0 && j >= 0)
	{
		int val1 = a[i];
		int val2 = b[j];
		int sum = val1 +val2 + carry;
		
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
		j--;
	}

	//  if first array is bigger 
	while(i >= 0)
	{
		int sum = a[i]+carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}



	//  if second array is bigger 
	while(j >= 0)
	{
		int sum = b[j]+carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}


	//  if carry is left 

	while(carry != 0)
	{
		int sum = carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}


	return(reverse(ans));
}

int main()
{
    vector<int>a = {1,2,3};
    vector<int>b = {9,9};
    vector<int> ans = findArraySum(a, a.size(), b, b.size());
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}