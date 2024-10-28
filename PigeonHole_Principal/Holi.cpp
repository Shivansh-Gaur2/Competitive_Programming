#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(int u, int parent, vector<vector<pair<int, int>>> &adj, ll &ans, int n) {
    int currentTreeSize = 1;
    for (auto node : adj[u]) {
        int v = node.first;
        int w = node.second;

        if (v == parent) continue;

        int childTreeSize = dfs(v, u, adj, ans, n);
        ll edgeContribution = 2LL * min(childTreeSize, n - childTreeSize) * w;
        ans += edgeContribution;
        currentTreeSize += childTreeSize;
    }
    return currentTreeSize;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> adj(n + 1);  // Adjust size based on n
        int u, v, w;

        for (int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        ll ans = 0;
        dfs(1, -1, adj, ans, n);
        cout << ans << endl;
    }
}
