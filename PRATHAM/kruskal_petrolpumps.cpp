#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int kruskal(int V, vector<Edge>& edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end(), compareEdges);

    int mstWeight = 0;
    for (Edge e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            ds.unionSets(e.u, e.v);
            mstWeight += e.weight;
        }
    }

    return mstWeight;
}

int main() {
    int V = 5; // Number of petrol pumps
    vector<Edge> edges = {
        {0, 1, 10},
        {1, 2, 15},
        {2, 3, 20},
        {3, 4, 25},
        {0, 2, 30},
        {1, 3, 35}
    };

    int mstWeight = kruskal(V, edges);
    cout << "Minimum cost to lay down pipelines: " << mstWeight << endl;

    return 0;
}
