

// Rat-Maze problem  --> link: practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> arr)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('D');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('U');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('L');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    // right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('R');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    if (arr[0][0] == 0)
    {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(arr, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of an array " << endl;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }

    for (int i = 0; i < findPath(arr, n).size(); i++)
    {
        cout<<findPath(arr, n)[i]<<" ";
    }
    
    return 0;
}