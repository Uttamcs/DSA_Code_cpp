// Implementing Dijkstra Algorithm (using set Queue)


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
        set<pair<int, int>> st;
        vector<int>dist (v, INT_MAX);

        dist[s] = 0;
        st.insert({0,s});

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(dis + edgeWeight < dist[adjNode])
                {
                    if(dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
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