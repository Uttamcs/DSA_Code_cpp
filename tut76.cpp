// K-th Largest Sum Subarray
// https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTabValue=PROBLEM



// // Approach - I
// #include<bits/stdc++.h>
// using namespace std;
// int getKthLargest(vector<int> &arr, int k)
// {
// 	//	Write your code here.
// 	int n = arr.size();
// 	vector<int>sumStore;
// 	for(int i = 0; i<n; i++)
// 	{
// 		int sum = 0;
// 		for(int j = i; j<n; j++)
// 		{
// 			sum+=arr[j];
// 			sumStore.push_back(sum);
// 		}
// 	}
// 	sort(sumStore.begin(), sumStore.end());
// 	return  sumStore[sumStore.size() - k];
// }
// int main()
// {
//     vector<int>vc = {1, -2, 3, -4, 5};
//     int k = 2;
//     cout<<getKthLargest(vc, k)<<endl;
//     return 0;
// }










// // Approach - II (We will use priority_queue)

// #include<bits/stdc++.h>
// using namespace std;
// int getKthLargest(vector<int> &arr, int k)
// {
//     priority_queue<int, vector<int>, greater<int>>miniHeap;

//     int n = arr.size();
//     for (size_t i = 0; i < n; i++)
//     {
//         int sum  = 0;
//         for (size_t j = i; j < n; j++)
//         {
//             sum+=arr[j];
//             if(miniHeap.size()< k)
//             {
//                 miniHeap.push(sum);
//             }
//             else
//             {
//                 if(sum > miniHeap.top())
//                 {
//                     miniHeap.pop();
//                     miniHeap.push(sum);
//                 }
//             }
//         }
//     }
//     return miniHeap.top();
// }
// int main()
// {
//     vector<int>vc = {1, -2, 3, -4, 5};
//     int k = 2;
//     cout<<getKthLargest(vc, k)<<endl;
//     return 0;
// }












// // Merge K Sorted Arrays
// // https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTabValue=PROBLEM

// #include<bits/stdc++.h>
// using namespace std;
// #include <bits/stdc++.h> 
// class node
// {
//     public:
//     int data;
//     int i; 
//     int j;

//     node(int data, int row, int col)
//     {
//         this->data = data;
//         i = row;
//         j = col;
//     }
// };

// class compare
// {
//     public:
//     bool operator()(node* a, node* b)
//     {
//         return a->data > b->data;
//     }
// };

// vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
// {
//     // Step 1 : Push all the k nodes of kArrays in heap
//     priority_queue<node*, vector<node*>, compare> mini;
//     for(int i = 0; i<k ; i++)
//     {
//         node* temp = new node(kArrays[i][0], i, 0);
//         mini.push(temp);
//     }


//     // Step 2: Insert next element of the same array into ans
//     vector<int>ans;
//     while(mini.size() > 0)
//     {
//         node* temp = mini.top();
//         ans.push_back(temp ->data);
//         mini.pop();

//         int i = temp -> i;
//         int j= temp -> j;

//         if(j+1 < kArrays[i].size() )
//         {
//             node* next = new node(kArrays[i][j+1], i, j+1);
//             mini.push(next);
//         }
//     }
//     return ans;
// }

// int main()
// {
//     vector<vector<int>> arr = {{3,5,9}, {1,2,3,8}};
//     int k = 2;
//     vector<int>res = mergeKSortedArrays(arr, k);
//     for(auto it: res)
//     {
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     return 0;
// }












// Merge K sorted Linked List

#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    return 0;
}