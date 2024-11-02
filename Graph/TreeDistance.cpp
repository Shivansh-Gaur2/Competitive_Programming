#include <bits/stdc++.h>
using namespace std;

int bfs(int node, vector<bool>& vis, unordered_map<int, list<int>>& adj) {
    queue<int> q;
    q.push(node);
    vis[node] = true;
    int maxDistance = -1; // Start with -1 since we will count edges

    while (!q.empty()) {
        int size = q.size();
        maxDistance++; // Increase the distance level
        for (int i = 0; i < size; i++) {
            int f = q.front();
            q.pop();
            for (auto nbr : adj[f]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
    }
    return maxDistance; // Return the maximum distance
}

vector<int> treeDistances(int n, vector<vector<int>> edges) {
    unordered_map<int, list<int>> adj;

    for (auto it : edges) {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n, 0);
    for (int i = 1; i <= n; i++) {
        vector<bool> vis(n + 1, false);
        ans[i - 1] = bfs(i, vis, adj); // Store results directly
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    vector<int> distances = treeDistances(n, edges);

    for (int distance : distances) {
        cout << distance << " ";
    }
    cout << endl;
    return 0;
}
