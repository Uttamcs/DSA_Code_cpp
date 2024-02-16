/*
// Subset of an array by using recursion
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> arr, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }
    
    // exclude
    solve(arr, output, index + 1, ans);

    // include
    int element = arr[index];
    output.push_back(element);
    solve(arr, output, index + 1, ans);

}
vector<vector<int>> subsets(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(arr, output, index, ans);
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int size = arr.size();
    vector<vector<int>> ans = subsets(arr);
    for (int i = 0; i < (ans.size()); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << subsets(arr)[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

*/