// // Smallest Range Covering Elements from K Lists
// // https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/


// class node
// {
//     public:
//     int data;
//     int row;
//     int col;

//     node(int d, int r, int c)
//     {
//         data = d;
//         row = r;
//         col = c;
//     }
// };
// class compare
// {
//     public:
//     bool operator()(node*a , node* b)
//     {
//         return a-> data > b -> data;
//     }
// };
// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int mini = INT_MAX, maxi = INT_MIN;
//         priority_queue<node*, vector<node*>, compare>pq;

//         for(int i=0; i<nums.size(); i++)
//         {
//             int element = nums[i][0];
//             mini = min(mini, element);
//             maxi = max(maxi, element);
//             pq.push(new node(element, i, 0));
//         }
//         int start = mini, end = maxi;
//         while(!pq.empty())
//         {
//             node* temp = pq.top();
//             pq.pop();
            
//             mini = temp->data;
//             if(maxi - mini < end - start)
//             {
//                 start = mini;
//                 end = maxi;
//             }
//             int row = temp -> row, col = temp -> col;

//             if(col + 1<  nums[row].size())
//             {
//                 maxi = max(maxi , nums[row][col + 1]);
//                 pq.push(new node( nums[row][col + 1], row, col + 1));

//             }
//             else
//             {
//                 break;
//             }
//         }
//         return {start,end};
//     }
// };







