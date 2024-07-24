// Strongly Connected Components (Kosaraju's Algo)
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1


#include <bits/stdc++.h>
using namespace std;

void dfs3(int node, vector<int> &vis, vector<int> adjT[])
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT);
        }
    }
}

void dfs(int i, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[i] = 1;
    for (auto nbr : adj[i])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, adj, st);
        }
    }
    st.push(i);
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    // Step 1: Do DFS and store vertices according to their finishing times
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // Step 2: Transpose the graph
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // Step 3: Process all vertices in order defined by the stack
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs3(node, vis, adjT);
        }
    }
    return scc;
}

int main()
{
    int V = 5;
    vector<pair<int, int>> edges{
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge.first].push_back(edge.second);
    }

    cout << kosaraju(V, adj) << endl;

    return 0;
}
