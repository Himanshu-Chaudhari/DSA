#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Greedy graph coloring algorithm
void greedyColoring(vector<vector<int>>& adj, int V) {
    vector<int> result(V, -1);
    result[0] = 0;
    vector<bool> available(V, false);

    for (int u = 1; u < V; ++u) {
        for (int i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = true;
            }
        }

        int cr = 0;
        while (cr < V) {
            if (!available[cr]) {
                break;
            }
            cr++;
        }

        result[u] = cr;

        for (int i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }
    }

    for (int u = 0; u < V; ++u) {
        cout << "Vertex " << u << " ---> Color " << result[u] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> g1(V);

    // Add edges to the graph g1
    addEdge(g1, 0, 1);
    addEdge(g1, 0, 2);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);

    cout << "Coloring of graph 1:" << endl;
    greedyColoring(g1, V);

    vector<vector<int>> g2(V);

    // Add edges to the graph g2
    addEdge(g2, 0, 1);
    addEdge(g2, 0, 2);
    addEdge(g2, 1, 2);
    addEdge(g2, 1, 4);
    addEdge(g2, 2, 4);
    addEdge(g2, 4, 3);

    cout << "\nColoring of graph 2:" << endl;
    greedyColoring(g2, V);

    return 0;
}