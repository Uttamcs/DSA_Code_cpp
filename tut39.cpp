#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> arr, int index, vector<vector<int>>& ans)
{
    // base class
    if (index>= arr.size())
    {
        ans.push_back(arr);
        return ;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        solve(arr, index+1, ans);
        // backtracking
        swap(arr[index], arr[i]);
    }
    
}
vector<vector<int>> permute(vector<int>& arr)
{
    vector<vector<int>> ans;
    int index=0;
    solve(arr, index,ans);
    return ans;
}
int main()
{
    vector<int> arr={1,2,3};
    int size=permute(arr).size();
    
    for (int i = 0; i < (size); i++)
    {
        for (int j = 0; j < permute(arr)[i].size(); j++)
        {
            cout << permute(arr)[i][j] << " ";
        }
        cout << endl;
    }    return 0;
}