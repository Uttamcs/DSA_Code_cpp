// Detect a cycle in Directed graph


#include<bits/stdc++.h>
using namespace std;

void topo(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adjList, stack<int>& st)
{
    visited[src]= true;
    for(auto neighbour : adjList[src])
    {
        if(!visited[neighbour])
        {
            topo(neighbour, visited, adjList, st);
        }
    }
    st.push(src);
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
    int n = 6;
    vector<vector<int>> edges = {{5,0},{5,2},{4,0},{4,1},{2,3},{3,1}};
    prepareAdj(n, edges,adjList);
    vector<int>ans;
    stack<int>st;
    unordered_map<int, bool>visited;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            topo(i, visited, adjList, st);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}