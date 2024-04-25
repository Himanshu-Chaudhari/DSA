// 1
// 5
// abb??
// 12100000000000000000000000


#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <limits>
#include <stack>

using namespace std;

vector<pair<pair<int, int>, int>> prims(int nodes, int edges, vector<pair<pair<int, int>, int>> g, int src) {
    // Adjacency list representation of the graph
    unordered_map<int, list<pair<int, int>>> adj;
    
    // Creating adjacency list
    for (auto& edge : g) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Key values of vertices (initialized to infinity)
    vector<int> key(nodes + 1, numeric_limits<int>::max());
    // Whether a node is added to MST
    vector<bool> mstAdded(nodes + 1, false);
    // Parent of each vertex in MST
    vector<int> parent(nodes + 1, -1);

    // Algo begins
    key[src] = 0;
    parent[src] = -1;

    for (int i = 1; i < nodes; i++) {
        int u = -1;
        int mini = numeric_limits<int>::max();

        // Finding the node with min value
        for (int v = 1; v <= nodes; v++) {
            if (!mstAdded[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark min node as true in mstAdded
        mstAdded[u] = true;

        // Update key values and parent pointers based on the selected vertex
        for (auto& it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (!mstAdded[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= nodes; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main() {
    int nodes = 5, edges = 7;
    vector<pair<pair<int, int>, int>> g = {{{1,5},7},{{2,5},1},{{3,5},2},{{1,2},3},{{1,3},5},{{1,4},1},{{3,4},7}};
    int src = 3;

    vector<pair<pair<int, int>, int>> mst = prims(nodes, edges, g, src);

    cout << "Edges in MST:\n";
    for (auto& edge : mst) {
        cout << edge.first.first << " " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}


