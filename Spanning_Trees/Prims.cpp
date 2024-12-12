#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<pair<int, int>>*l;
    public:
    Graph(int v){
        V = v;
        l = new vector<pair<int, int>>[V];


    }

    void addEdge(int x, int y, int w){
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prims_mst(){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        bool * visited = new bool[V]{0};
        int ans = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto best = pq.top();
            pq.pop();

            int to = best.second;
            int wt = best.first;

            if(visited[to]){
                continue;
            }

            ans += wt;
            visited[to] = 1;

            for(auto x : l[to]){
                if(visited[x.first] == 0){
                    pq.push({x.second, x.first});
                }
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

    cout << g.prims_mst() << endl;
}