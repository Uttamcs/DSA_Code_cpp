#include <bits/stdc++.h> 
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1; i<n; i++){
        for(int j=0;j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void print(vector<int> arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    vector<int> arr={5,52,5,62,2,5,65,32};
    bubbleSort(arr,arr.size()-1);
    print(arr,arr.size());
    return 0;
}
