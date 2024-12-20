#include <bits/stdc++.h>
using namespace std;

vector<int>bellman_ford(int V, int src, vector<vector<int>> edges){
    vector<int>dist(V+1, INT_MAX);

    dist[src] = 0;

    for(int i = 0 ;i < V-1; i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
            cout << "Negative cycle is found!!" << endl;
            exit(0);
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i = 0 ; i < m ; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }

    vector<int> distances = bellman_ford(n, 1, edges);

    for(int i = 1 ; i <= n; i++){
        cout << "Node " << i << "is at dist " << distances[i] << endl;
    }

    return 0;
}