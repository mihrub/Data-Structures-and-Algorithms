#include <bits/stdc++.h>
using namespace std;

int V, best;
vector<vector<int>> adj;
vector<int> color, bestColor;

bool isSafe(int v, int c) {
    for (int u = 0; u < V; u++)
        if (adj[v][u] && color[u] == c) return false;
    return true;
}

// used = number of distinct colors used so far
void solve(int v, int used) {
    if (used >= best) return;          // prune: can't beat best
    if (v == V) {
        best = used;
        bestColor = color;
        return;
    }
    for (int c = 1; c <= used + 1; c++) {   // existing colors, or one new color
        if (isSafe(v, c)) {
            color[v] = c;
            solve(v + 1, max(used, c));
            color[v] = 0;                   // backtrack
        }
    }
}

int main() {
    int E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    adj.assign(V, vector<int>(V, 0));
    color.assign(V, 0);

    cout << "Enter " << E << " edges (u v), 0-indexed:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    best = V + 1;
    solve(0, 0);

    cout << "Chromatic number = " << best << "\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " -> Color " << bestColor[i] << "\n";
    return 0;
}