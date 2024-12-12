#include <bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<pair<int, int>>* l;
    public :
    Graph(int v){
        this -> v = v;
        l = new vector<pair<int,int>>[v];
    }

    void addEdge(int x, int y, int w, bool undir = true){
        l[x].push_back({w, y});
        if(undir){
        l[y].push_back({w, x});
        }
    }

    int dijkstra(int src, int dest){
        vector<int> dist(v, INT_MAX);
        set<pair<int,int>> s;

        dist[src] = 0;
        s.insert({0, src});

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);

            for(auto [edgeWeight, nbr] : l[node]){
                if(distTillNow + edgeWeight < dist[nbr]){
                    auto f = s.find({dist[nbr] , nbr});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    dist[nbr] = distTillNow + edgeWeight;
                    s.insert({dist[nbr] , nbr}); 
                }
            }
        }

        for(int i = 0 ;i < v; i++){
            cout << "Node " << i << " is at dist " << dist[i] << endl;
        }
        return dist[dest];
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);

    cout << g.dijkstra(0, 4) << endl;
}