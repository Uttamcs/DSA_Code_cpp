// Detect a cycle in Directed graph


#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adjList,  unordered_map<int, bool>& dfsVisited)
{
    visited[src]= true;
    dfsVisited[src]= true;

    for(auto neighbour : adjList[src])
    {
        if(!visited[neighbour])
        {
            bool ans = isCyclic(neighbour, visited, adjList, dfsVisited);
            if(ans){
                return true;
            }
        }
        else if(dfsVisited[neighbour]) return true;
    }
    dfsVisited[src] = false;
    return false;
}
void prepareAdj(int n, vector<vector<int>>& edge, unordered_map<int, list<int>>& adjList)
{
    for(int i= 0; i<edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];

        adjList[u].push_back(v);
    }
}
int main()
{
    unordered_map<int, list<int>> adjList;
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,3}};
    prepareAdj(n, edges,adjList);
    unordered_map<int, bool> visited;
    unordered_map<int, bool>dfsVisited;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclic(i, visited, adjList, dfsVisited);
            if(ans)
            {
                cout<<"Graph contains a loop"<<endl;
                return 0;
            }
        }
    }
    cout<<"Graph doesn't contains a cycle\n";
    return 0;
}