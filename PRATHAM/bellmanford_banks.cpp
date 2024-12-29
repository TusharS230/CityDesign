#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start) {
    queue<int> q;
    unordered_set<int> visited;
    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visiting ATM/Branch: " << node << endl;

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},  // ATM 0 is connected to 1, 2
        {0, 3},  // ATM 1 is connected to 0, 3
        {0, 3},  // ATM 2 is connected to 0, 3
        {1, 2}   // ATM 3 is connected to 1, 2
    };

    bfs(graph, 0); // Start BFS from ATM 0 (customer's location)

    return 0;
}
