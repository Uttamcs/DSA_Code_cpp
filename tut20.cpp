/*
// Given an array/list 'ARR' of integers . You have to reverse the array.
#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v){
    int s=0, e=v.size()-1;
    while (s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}


void print(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    vector<int> ans=reverse(v);
    cout<<"Printitng original array"<<endl;
    print(v);
    cout<<"Printitng reversed array"<<endl;
    print(ans);

    return 0;
}
*/

/*
// Given an array/list 'ARR' of integers and a position 'M'. You have to reverse the array after that position.

#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v, int m){
    int s=m, e=v.size()-1;
    while (s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}


void print(vector<int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int m;
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);
    v.push_back(17);
    v.push_back(13);
    v.push_back(32);
    v.push_back(14);

    vector<int> ans=reverse(v,3);
    cout<<"Printitng original array"<<endl;
    print(v);
    cout<<"Printitng reversed array"<<endl;
    print(ans );

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
void reverseArray(vector<int> &arr , int m)
{
    int s=m, e=arr.size()-1;
    while (s<=e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
int main(){
    int num, n,m,i=num;
    cin>>num;
    while(i>0)
    {
        cin>>n>>m;
        vector<int>v;
        int j=n;
        while(j>0){
            int k;
            cin>>k;
            v.push_back(k);
            j--;
        }
        i--;
    }
    return 0;
}

*/




/*

// Reverse The Array. Given an array/list 'ARR' of integers and a position 'M'. You have to reverse the array after that position.
// The very first line of input contains an integer 'T' denoting the number of test cases. The first line of every test case 
// contains one integer 'N' where 'N' denotes the number of elements and an integer 'M' which denotes after which position the 
// array has to be reversed. The second line of every test case contains 'N' space-separated integers which denote the elements
//  of the input array/list.

#include<bits/stdc++.h>
using namespace std;
void reverseArray(vector<int>&arr , int m)
{
	int s=m, e=arr.size()-1;
    while (s<=e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void print(vector<int> v){
    for (int i:v)
    {
        cout<<i<<" ";
    }
    
}
int main(){
    int num, n,m;
    cin>>num;
    while(num--)
    {
        cin>>n>>m;
        vector<int>v;
        int l=n;
        while(l--){
            int k;
            cin>>k;
            v.push_back(k);
        }
        reverseArray(v,m);
        print(v);
    }
    return 0;
}

*/



#include<bits/stdc++.h>
using namespace std;
void merge(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i=0, j=0, k=0;
    while (i<n && j<m)
    {
        if (arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }
    while (i<n)
    {
        arr3[k++]=arr1[i++];
    }
    while (j<m)
    {
        arr3[k++]=arr2[j++];
        
    }
}


void print(int ans[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0};

    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8);

    return 0;
}




