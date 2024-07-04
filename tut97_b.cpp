#include <bits/stdc++.h>
using namespace std;

// Class to represent the Disjoint Set data structure
class DisjointSet {
    vector<int> rank, parent, size;

public:
    // Constructor to initialize the data structures
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Initially, each node is its own parent
            size[i] = 1; // Initially, each set size is 1
        }
    }

    // Find the ultimate parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank to merge two sets
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size to merge two sets
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Function to find the weight of the Minimum Spanning Tree using Kruskal's Algorithm
int spanningTree(int V, vector<pair<int, int>> adj[]) {
    // Vector to store all edges along with their weights
    vector<pair<int, pair<int, int>>> edges;

    // Convert adjacency list to a list of edges
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            int adjNode = it.first;
            int wt = it.second;
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }

    // Create an instance of DisjointSet for union-find operations
    DisjointSet ds(V);

    // Sort edges based on their weights
    sort(edges.begin(), edges.end());

    int mstWt = 0; // Variable to store the weight of the MST

    // Iterate over all sorted edges
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // If u and v are in different sets, include this edge in the MST
        if (ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt; // Add the weight of this edge to the MST weight
            ds.unionBySize(u, v); // Union the sets containing u and v
        }
    }

    return mstWt; // Return the weight of the MST
}

int main() {
    int v = 3, e = 3;
    vector<pair<int, int>> adj[v];

    // Adding edges to the adjacency list
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    // Print the weight of the Minimum Spanning Tree
    cout << spanningTree(v, adj) << endl;
    return 0;
}
