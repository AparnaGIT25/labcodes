#include <bits/stdc++.h>
using namespace std;

int findMinKey(vector<int> &key, vector<bool> &mstSet, int n) {
    int minVal = INT_MAX, minIndex;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>> &graph, int n) {
    vector<int> parent(n); 
    vector<int> key(n, INT_MAX); 
    vector<bool> mstSet(n, false);

    key[0] = 0; 
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge   Weight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int n = graph.size();

    primMST(graph, n);
    return 0;
}
