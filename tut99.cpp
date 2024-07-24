// Articulation Point in a Graph


#include <bits/stdc++.h>
using namespace std;
void DFS(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artPoint, int &timer)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (int j = 0; j < adj[node].size(); j++)
    {
        int nbr = adj[node][j];
        if (nbr == parent)
            continue;
        if (visited[nbr])
        {
            low[node] = min(low[node], disc[nbr]);
        }
        else
        {
            child++;
            DFS(nbr, node, adj, visited, disc, low, artPoint, timer);
            low[node] = min(low[node], low[nbr]);

            if (parent != -1 && low[nbr] >= disc[node])
            {
                artPoint[node] = true;
            }
        }
    }
    if (parent == -1 && child > 1)
    {
        artPoint[node] = true;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<bool> artPoint(V, false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, false);
    int timer = 0;

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            DFS(i, -1, adj, visited, disc, low, artPoint, timer);
        }
    }

    vector<int> ans;
    for (int i = 0; i < V; ++i)
    {
        if (artPoint[i])
            ans.push_back(i);
    }

    return ans.empty() ? vector<int>{-1} : ans;
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int V = 5;
    vector<int> adj1[V + 1];
    addEdge(adj1, 1, 2);
    addEdge(adj1, 2, 3);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 3, 4);
    addEdge(adj1, 4, 5);
    vector<int>ans = articulationPoints(V, adj1);
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}