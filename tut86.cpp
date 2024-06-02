; // BFS Traversal of a graph

#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        //  direction = 1 -> directed

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void bfs(int startNode)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        queue<int> q;

        // mark true in visited map
        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        for(auto it:ans)
        {
            cout<<it<<" ,";
        }
        cout<<"\n";
    }
};
int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    graph g;
    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating a directed graph
        g.addEdge(u, v, 1);
    }

    int startNode;
    cout << "Enter the starting node for bfs " << endl;
    cin >> startNode;

    cout << "Printing bfs of the graph with starting node " << startNode << endl;
    g.bfs(startNode);
    return 0;
}