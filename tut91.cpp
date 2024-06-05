// Topological Sort using Kahn's Algorithm

#include <bits/stdc++.h>
using namespace std;
void prepareAdj(int n, vector<vector<int>>& edge, vector<int> adjList[])
{
    for(int i= 0; i<edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];

        adjList[u].push_back(v);
    }
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // indegree vector maintain karo
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // 0 indegree wale ko queue m push kar do
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // chalo ab queue s nikaal k process kar do
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
int main()
{
    int n = 6;
    vector<int> adjList[n] ;
    vector<vector<int>> edges = {{5,0},{5,2},{4,0},{4,1},{2,3},{3,1}};
    prepareAdj(n, edges,adjList);
    vector<int>ans = topoSort(n, adjList);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}