#include <bits/stdc++.h>
using namespace std;


class DSU{
    int *parent;
    int *rank;

    public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];

        for(int i = 0; i < n; i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == -1){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
            parent[s2] = s1;
            rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int>> edgeList;
    int V;

    public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int x, int y, int w){
        edgeList.push_back({w, x, y});
    }

    int kruskal_mst(){
        sort(edgeList.begin(), edgeList.end());

        DSU s(V);

        int ans = 0;

        for(auto edge : edgeList){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(s.find(x) != s.find(y)){
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x-1, y-1, w);
    }

    cout << g.kruskal_mst() << endl;

    return 0;
}