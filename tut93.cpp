// Shortest Path in Undirected Graph

#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>>& edges, int n , int m , int s , int e)
{
    unordered_map<int, list<int>> adj;
    // prepare adjacency list
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int>parent;
    queue<int>q;

    q.push(s);
    parent[s]=-1;
    visited[s]= true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();


        for(auto neighbour : adj[frontNode])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }

    // find shortest path using parent vector

    vector<int>temp;

    int currNode = e;
    temp.push_back(currNode);

    while (currNode != s)
    {
        currNode = parent[currNode];
        temp.push_back(currNode);
    }

    
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    int start = 1, end = 8;
    int n = 8, m = 9;
    vector<vector<int>>edges = {{1,2},{2,5},{5,8},{1,3},{3,8},{1,4},{4,6},{6,7},{7,8}};
    vector<int>ans;
    ans= solve(edges, n, m, start, end);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}