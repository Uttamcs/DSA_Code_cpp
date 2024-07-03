// Bridges in a graph

// In a graphh theory , a bridge is an edge in a graph that increases the number of connected components in the graph when it's removed


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int& timer, vector<int>&low, vector<int>&disc, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, vector<vector<int>>& res)
{
    visited[node]= true;
    disc[node]= low[node] = timer++;

    for(auto nbr : adj[node])
    {
        if(nbr == parent) continue;
        else if(!visited[nbr])
        {
            dfs(nbr, node, timer,low, disc,visited,adj, res);
            low[node] = min(low[node], low[nbr]);


            // check edge is a bridge?
            if(low[nbr] > disc[node])
            {
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i= 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;
    int timer = 0;
    int parent = -1;
    vector<vector<int>> result;
    for(int i= 0; i < v; i++)
    {
        if(!visited[i])
        {
            dfs(i, parent, timer, low, disc, visited, adj, result);
        }
    }
    return result;
}
int main()
{
    return 0;
}