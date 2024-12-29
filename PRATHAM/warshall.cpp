#include <iostream>
#include <vector>

using namespace std;

// Function to apply Warshall's Algorithm
void warshall(vector<vector<int>>& reach) {
    int V = reach.size();
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
}

// Function to display the matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initial graph (reachability matrix)
    vector<vector<int>> reach = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 0}
    };

    // Apply Warshall's Algorithm
    warshall(reach);

    // Display the transitive closure matrix
    cout << "Transitive Closure Matrix:" << endl;
    displayMatrix(reach);

    return 0;
}


