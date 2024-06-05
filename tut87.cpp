// DFS traversal of a graph


#include<bits/stdc++.h>
using namespace std;
void dfs( unordered_map<int, list<int>>& adjList,  unordered_map<int, bool>& visited, vector<int>& component, int i)
{
    component.push_back(i);
    visited[i]= true;

    for(auto it:adjList[i])
    {
        if(!visited[it])
        {
            dfs(adjList, visited, component, it);
        }
    }
}
void prepareAdj( unordered_map<int, list<int>>& adjList, vector<vector<int>> &edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
vector<vector<int>> dfs(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int, list<int>>adj;
    vector<vector<int>> ans;
    unordered_map<int, bool>visited;

    // prepare adjacency list
    prepareAdj(adj, edges);

    // Traverse all the components of graph
    for(int i = 0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}
int main()
{
    unordered_map<int, list<int>>adj;
    vector<vector<int>> ans;
    unordered_map<int, bool>visited;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 5},{3, 6}, {7, 4}, {4, 8}, {7, 8}};
    
    int V = 9;

    // prepare adjacency list
    prepareAdj(adj, edges);

    // Traverse all the components of graph
    for(int i = 0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }
    for(auto it: ans)
    {
        for(auto num : it)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}