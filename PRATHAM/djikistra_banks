#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // {distance, node}

vector<int> dijkstra(int V, vector<vector<pii>>& adj, int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5; // Number of ATMs or bank locations
    vector<vector<pii>> adj(V);

    // Define the edges (ATM connections with distance)
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[1].push_back({2, 20});
    adj[2].push_back({1, 20});
    adj[2].push_back({3, 30});
    adj[3].push_back({2, 30});
    adj[3].push_back({4, 40});
    adj[4].push_back({3, 40});
    adj[0].push_back({4, 100});
    adj[4].push_back({0, 100});

    vector<int> dist = dijkstra(V, adj, 0); // Start from ATM 0

    cout << "Minimum distance from ATM 0 to other ATMs: \n";
    for (int i = 0; i < V; ++i) {
        cout << "ATM 0 to ATM " << i << ": " << dist[i] << endl;
    }

    return 0;
}
