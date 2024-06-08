// Shortest Path in Directed Acyclic Graphs

#include<bits/stdc++.h>
using namespace std;
class graph
{
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int weight)
    {
        pair<int, int>p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    // recursive dfs call for all its corresponding neighbour
    
    void dfs(int src,unordered_map<int, bool>& visited, stack<int>& s)
    {
        visited[src] = true;
        for(auto neighbour : adj[src])
        {
            if(!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(src);
    }

    void getShortestPath(int src , vector<int>& dist, stack<int>& topo)
    {
        dist[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT_MAX)
            {
                for(auto neigh : adj[top])
                {
                    if(dist[top]+neigh.second < dist[neigh.first]){
                        dist[neigh.first] = dist[top]+neigh.second ;
                    }
                }
            }
        }
    }
};
int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int n = 6;
    unordered_map<int, bool>visited;
    stack<int>s;

    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int>dist(n, INT_MAX);
    g.getShortestPath(src, dist, s);
    

    cout<<"Shortest Path will be  ";
    for (int i = 0; i < n; i++)
    {
        if(dist[i] == 2147483647)
        {
            cout<<"INF ";
        }
        else cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}