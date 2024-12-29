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
    int V = 5; // Number of petrol pumps
    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[1].push_back({2, 15});
    adj[2].push_back({1, 15});
    adj[2].push_back({3, 20});
    adj[3].push_back({2, 20});
    adj[3].push_back({4, 25});
    adj[4].push_back({3, 25});
    adj[0].push_back({4, 50});
    adj[4].push_back({0, 50});

    vector<int> dist = dijkstra(V, adj, 0); // Start from pump 0

    cout << "Minimum distance from pump 0 to other pumps: \n";
    for (int i = 0; i < V; ++i) {
        cout << "Pump 0 to Pump " << i << ": " << dist[i] << endl;
    }

    return 0;
}
