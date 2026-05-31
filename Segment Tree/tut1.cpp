#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<int> segmentTree;

void buildTree(int idx, int start, int end)
{
    if (start == end)
    {
        segmentTree[idx] = nums[start];
        return;
    }

    int mid = start + (end - start) / 2;

    buildTree(2 * idx + 1, start, mid);
    buildTree(2 * idx + 2, mid + 1, end);

    segmentTree[idx] =
        segmentTree[2 * idx + 1] +
        segmentTree[2 * idx + 2];
}

int main()
{
    cin >> n;

    nums.resize(n);
    segmentTree.resize(4 * n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    buildTree(0, 0, n - 1);

    cout << "Root sum = " << segmentTree[0] << '\n';

    return 0;
}