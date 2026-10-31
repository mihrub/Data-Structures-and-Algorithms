#include <bits/stdc++.h>
using namespace std;

int V, m;
vector<vector<int>> adj;
vector<int> color;

bool isSafe(int v, int c) {
    for (int u = 0; u < V; u++)
        if (adj[v][u] && color[u] == c) return false;
    return true;
}

bool solve(int v) {
    if (v == V) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (solve(v + 1)) return true;
            color[v] = 0;   // backtrack
        }
    }
    return false;
}

int main() {
    int E;
    cout << "Enter vertices, edges, m: ";
    cin >> V >> E >> m;

    adj.assign(V, vector<int>(V, 0));
    color.assign(V, 0);

    cout << "Enter " << E << " edges (u v), 0-indexed:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    if (solve(0)) {
        cout << "YES, colorable with " << m << " colors:\n";
        for (int i = 0; i < V; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << "\n";
    } else {
        cout << "NO, not colorable with " << m << " colors.\n";
    }
    return 0;
}