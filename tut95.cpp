// Implementing Dijkstra Algorithm (using priority Queue)

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v , int weight)
    {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }
    vector<int> dijKstra(int v, int s)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>dist (v, INT_MAX);

        dist[s] = 0;
        pq.push({0,s});

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();

            int dis = top.first;
            int node = top.second;

            for(auto it: adj[node])
            {
                int edgeWeight = it.second;
                int adjNode = it.first;

                if(dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
int main()
{
    graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,3);
    g.addEdge(2,0,6);
    int v = 3, s = 2;
    vector<int>ans;

    ans = g.dijKstra(v, s);

    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}