// Detect a cycle in undirected Graph

#include<bits/stdc++.h>
using namespace std;


void prepareAdj(vector<vector<int>>& edges, int n, int m,  unordered_map<int, list<int>>& adjList)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
bool isCyclicBFS(int src,unordered_map<int , bool>& visited, unordered_map<int, list<int>>& adjList )
{
    unordered_map<int, int>parent;
    queue<int>q;

    visited[src] = true;
    parent[src] = -1;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto i: adjList[frontNode])
        {
            if(visited[i] == true && i != parent[frontNode])
            {
                return true;
            }
            else if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = frontNode;
            }
        }
    }
    return false;
}
bool isCyclicDFS(int src, int parent, unordered_map<int , bool>& visited, unordered_map<int, list<int>>& adjList)
{
    visited[src] = true;

    // recursive call for its all neighbour
    for(auto it: adjList[src])
    {
        if(!visited[it])
        {
            bool cycleDetected = isCyclicDFS(it, src , visited, adjList);
            if(cycleDetected == true)
            {
                return true;
            }
        }
        else if(it != parent)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n = 3, m = 3;
    vector<vector<int>> edges = {{1,2},{2,3},{3,1}};
    unordered_map<int , bool>visited;
    unordered_map<int, list<int>>adjList;
    prepareAdj(edges, n, m , adjList);
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            // if(isCyclicBFS(i, visited, adjList))
            // {
            //     cout<<"Graph contains a cycle"<<endl;
            //     return 0;
            // }
            if(isCyclicDFS(i,-1, visited, adjList))
            {
                cout<<"Graph contains a cycle"<<endl;
                return 0;
            }
        }
    }
    cout<<"Graph doesn't contains a cycle"<<endl;
 
    return 0;
}