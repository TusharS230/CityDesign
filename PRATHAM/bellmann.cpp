#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool bellmanFord(int V, int start, vector<Edge>& edges, vector<int>& dist) {
    dist.assign(V, INT_MAX);
    dist[start] = 0;

    // Relax all edges (V - 1) times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Graph contains a negative-weight cycle." << endl;
            return false;
        }
    }

    return true;
}

int main() {
    int V = 5; // Number of fuel distribution centers
    vector<Edge> edges = {
        {0, 1, 5},   // Road from center 0 to 1 with a weight of 5
        {1, 2, -2},  // Road from center 1 to 2 with a negative impact (e.g., closure or delay)
        {1, 3, 3},   // Road from center 1 to 3 with a weight of 3
        {2, 4, 4},   // Road from center 2 to 4 with a weight of 4
        {3, 2, 6},   // Road from center 3 to 2 with a weight of 6
        {0, 3, 8}    // Road from center 0 to 3 with a weight of 8
    };

    vector<int> dist;
    int start = 0; // Start from fuel distribution center 0

    if (bellmanFord(V, start, edges, dist)) {
        cout << "Minimum distances from center " << start << " to other centers:" << endl;
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                cout << "Center " << i << ": Unreachable" << endl;
            } else {
                cout << "Center " << i << ": " << dist[i] << endl;
            }
        }
    }

    return 0;
}

