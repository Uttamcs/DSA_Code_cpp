// // Kth smallest element
// // https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// #include <bits/stdc++.h>
// using namespace std;

// int kthSmallest(int arr[], int l, int r, int k) {
//     priority_queue<int> pq;
    
//     // Step 1: Push first k elements into the max heap
//     for(int i = l; i < l + k; i++) {
//         pq.push(arr[i]);
//     }

//     // Step 2: Process the remaining elements
//     for(int i = k; i <= r; i++) {
//         if(arr[i] < pq.top()) {
//             pq.pop();
//             pq.push(arr[i]);
//         }
//     }
    
//     // The kth smallest element will be at the top of the max heap
//     return pq.top();
// }

// int main() {
//     int arr[] = {7, 10, 4, 3, 20, 15};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 3;
//     int l = 0, r = n - 1;
    
//     int result = kthSmallest(arr, l, r, k);
//     cout << "The " << k << "rd smallest element is " << result << endl;

//     return 0;
// }








// // Is Binary Tree Heap or not
// #include<bits/stdc++.h>
// using namespace std;
// class node
// {
//     public:
//     int data;
//     node* left;
//     node* right;

//     node(int data)
//     {
//         this->data =data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// int cntNodes(node* root)
// {
//     if(root == NULL)
//     {
//         return 0;
//     }
//     return 1+ cntNodes(root->left) + cntNodes(root->right);
// }
// bool isCBT(node* root , int index, int totalCount)
// {
//     if(root == NULL)
//     {
//         return true;
//     }

//     if(index >= totalCount)
//     {
//         return false;
//     }
//     else
//     {
//         bool left = isCBT(root->left, 2*index+1, totalCount);
//         bool right = isCBT(root->right, 2*index+2, totalCount);
//         return (left && right);
//     }
// }
// bool isMaxOrder(node* root)
// {
//     if(root-> left == NULL && root->right == NULL)
//     {
//         return true;
//     }
//     if(root->right == NULL)
//     {
//         return (root->data > root->left->data);
//     }
//     else
//     {
//         bool left = isMaxOrder(root->left);
//         bool right = isMaxOrder(root->right);

//         return (left && right && (root->data > root->left->data && root->data > root->right->data));
//     }
// }
// void isHeap(node* root)
// {
//     int index  = 0;
//     int totalCnt  = cntNodes(root);
//     if(isCBT(root, index, totalCnt) && isMaxOrder(root))
//     {
//         cout<<"Yes, It is a heap"<<endl;
//     }
//     else
//     {
//         cout<<"Yes, It is not a heap"<<endl;
//     }
// }
// int main()
// {
//     node* root = new node(5);
//     root->left = new node(2);
//     root->right = new node(3);
//     isHeap(root);
//     return 0;
// }














// // Merge two binary max-Heap
// #include<bits/stdc++.h>

// using namespace std;
// void heapify(vector < int > & arr, int n, int i) {
//   int largest = i;
//   int left = 2 * i + 1;
//   int right = 2 * i + 2;

//   if (left < n && arr[largest] < arr[left]) {
//     largest = left;
//   }
//   if (right < n && arr[largest] < arr[right]) {
//     largest = right;
//   }
//   if (largest != i) {
//     swap(arr[largest], arr[i]);
//     heapify(arr, n, largest);
//   }
// }
// vector < int > mergeHeaps(vector < int > & a, vector < int > & b, int n, int m) {
//     // Step 1: Merge both the array
//     vector < int > ans;
//     for (auto it: a) {
//       ans.push_back(it);
//     }
//     for (auto it: b) {
//       ans.push_back(it);
//     }

//     // Step 2 : Heapify this array
//     int size = ans.size();
//     //biuld heap for 0- based indexing
//     for (int i = size / 2 - 1; i >= 0; i--) {
//       heapify(ans, size, i);
//     }
//     return ans;
//   }
// int main() {
//     int n =4, m =3;
//     vector<int>a = {10,5,6,2};
//     vector<int>b = {12,7,9};
//     vector<int>res = mergeHeaps(a,b,n,m);
//     for(auto it : res)
//     {
//         cout<<it<<" ";
//     }
//   return 0;
// }











// // Minimum cost of ropes
// #include<bits/stdc++.h>

// using namespace std;
// long long minCost(vector < int > & arr, long long n) {
//   // Create min heap
//   priority_queue < long long, vector < long long > , greater < long long >> pq;
//   for (long long i = 0; i < n; i++) {
//     pq.push(arr[i]);
//   }
//   long long cost = 0;
//   while (pq.size() > 1) {
//     long long a = pq.top();
//     pq.pop();

//     long long b = pq.top();
//     pq.pop();

//     long long sum = a + b;
//     cost += sum;

//     pq.push(sum);
//   }
//   return cost;
// }
// int main() {
//   int n = 4;
//   vector < int > arr = {4,3,2,6};
//   cout << minCost(arr, n);
//   return 0;
// }










// // Convert BST to Min Heap


// #include <bits/stdc++.h> 
// using namespace std;

// class node {
// public:
//     int data;
//     node* left;
//     node* right;

//     node(int data) {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// void inOrder(node* root, vector<int>& arr) {
//     if (root == NULL) {
//         return;
//     }
//     inOrder(root->left, arr);
//     arr.push_back(root->data);
//     inOrder(root->right, arr);
// }

// void preOrder(node* root, vector<int>& arr, int& idx) {
//     if (root == NULL) {
//         return;
//     }
//     root->data = arr[idx++];
//     preOrder(root->left, arr, idx);
//     preOrder(root->right, arr, idx);
// }

// node* convertBST(node* root) {
//     vector<int> arr;
//     inOrder(root, arr);
//     sort(arr.begin(), arr.end());
//     int idx = 0;
//     preOrder(root, arr, idx);
//     return root;
// }

// void printInOrder(node* root) {
//     if (root == NULL) {
//         return;
//     }
//     printInOrder(root->left);
//     cout << root->data << " ";
//     printInOrder(root->right);
// }

// int main() {
//     node* root = new node(10);
//     root->left = new node(2);
//     root->right = new node(7);
//     root->left->left = new node(8);
//     root->left->right = new node(4);

//     root = convertBST(root);

//     cout << "In-order traversal of the converted BST: ";
//     printInOrder(root);
//     cout << endl;

//     return 0;
// }

