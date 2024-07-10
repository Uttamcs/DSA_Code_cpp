// Bridges in a graph


#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and find bridges
void dfs(int node, int parent, int& timer, vector<int>& low, vector<int>& disc, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, vector<vector<int>>& res) {
    visited[node] = true;              // Mark the current node as visited
    disc[node] = low[node] = timer++;  // Initialize discovery time and low value

    for (auto nbr : adj[node]) {       // Traverse all adjacent vertices
        if (nbr == parent) continue;   // If the adjacent vertex is the parent, skip it

        if (!visited[nbr]) {           // If the adjacent vertex is not visited
            dfs(nbr, node, timer, low, disc, visited, adj, res); // Perform DFS on the adjacent vertex
            low[node] = min(low[node], low[nbr]); // Update the low value of the current node

            // Check if the edge is a bridge
            if (low[nbr] > disc[node]) {
                vector<int> ans = {node, nbr}; // Create a vector to store the bridge
                res.push_back(ans);            // Add the bridge to the result
            }
        } else {
            // Update the low value for back edges
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

// Function to find all bridges in the graph
vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj; // Adjacency list representation of the graph
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w); // Add edge u-w
        adj[w].push_back(u); // Add edge w-u (undirected graph)
    }

    vector<int> disc(v, -1);     // Discovery times of visited vertices
    vector<int> low(v, -1);      // Earliest visited vertex reachable from subtree
    unordered_map<int, bool> visited; // Visited array
    int timer = 0;               // Timer to keep track of discovery times
    vector<vector<int>> result;  // Result to store all bridges

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {       // If the vertex is not visited
            dfs(i, -1, timer, low, disc, visited, adj, result); // Perform DFS from the vertex
        }
    }
    return result;               // Return the result containing all bridges
}

int main() {
    int v = 5, e = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}};
    
    vector<vector<int>> ans = findBridges(edges, v, e); // Find bridges in the graph

    for (auto row : ans) {       // Print all bridges
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
