// Rat in a maze problem
// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030

// Time Complexity => O(4^n*n)
// Space Complexity => O(n*m)


#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newX, int newY, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) &&
        (!visited[newX][newY]) && (arr[newX][newY] == 1))
    {
        return true;
    }
    else
        return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, string path, vector<string> &ans)
{
    // Base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[x][y] = true;

    // 4-Movements possible either 'D', 'L', 'R', 'U'
    
    // Down
    if (isSafe(x + 1, y, visited, arr, n))
    {
        // Recursive call
        solve(x + 1, y, arr, n, visited, path + 'D', ans);
    }

    // Left
    if (isSafe(x, y - 1, visited, arr, n))
    {
        solve(x, y - 1, arr, n, visited, path + 'L', ans);
    }

    // Right
    if (isSafe(x, y + 1, visited, arr, n))
    {
        // Recursive call
        solve(x, y + 1, arr, n, visited, path + 'R', ans);
    }

    // Up
    if (isSafe(x - 1, y, visited, arr, n))
    {
        // Recursive call
        solve(x - 1, y, arr, n, visited, path + 'U', ans);
    }



    
    // Down, Left, Right, Up
    // vector<pair<int,int>> moves{{1,0}, {0,-1}, {0,1}, {-1,0}};
    // for (auto&i : moves) {
    //     int newX = x + i.first;
    //     int newY = y + i.second;

    //     if (isSafe(newX, newY, visited, arr, n)) {
    //         // recursive call
    //         solve(newX, newY, arr, n, visited, path +
    //         (i.first == 1 ? 'D' : i.first == -1 ? 'U' : i.second == -1 ? 'L' : 'R'), ans);
    //     }
    // }

    

    // Unmark the cell as visited for backtracking
    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (arr[0][0] == 0)
        return ans;

    solve(0, 0, arr, n, visited, path, ans);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = searchMaze(arr, n);
    for (const auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
