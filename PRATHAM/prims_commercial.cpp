#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // {cost, node}

int prim(int V, vector<vector<pii>>& adj) {
    vector<bool> visited(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalCost += cost;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    return totalCost;
}

int main() {
    int V = 4; // Number of stores
    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});

    int totalCost = prim(V, adj);
    cout << "Minimum cost to install HVAC system: " << totalCost << endl;

    return 0;
}