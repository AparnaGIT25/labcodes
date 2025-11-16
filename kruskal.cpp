#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n = 4, e = 5;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);

    cout << "Edges in MST (Kruskal):\n";

    int mstWeight = 0;
    for (auto &edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            cout << edge.u << " - " << edge.v << "  w=" << edge.w << "\n";
            mstWeight += edge.w;
            dsu.unite(edge.u, edge.v);
        }
    }

    cout << "Total weight: " << mstWeight << "\n";
    return 0;
}
