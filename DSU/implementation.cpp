#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int find(int node, int par[]){
    if(par[node] == -1){
        return node;
    }
    return find(par[node], par);
}

void union_set(int u, int v, int par[]){
    int s1 = find(u, par);
    int s2 = find(v, par);
    if(s1 != s2){
        par[s2] = s1;
    }
}

vector<bool> DSU(vector<vector<int>>query)
{
    vector<bool> ans;
    int par[N];
    fill(par, par + N, -1);
    for(auto it : query){
        int op = it[0];
        int u = it[1];
        int v = it[2];
        
        if(op == 1){
            union_set(u, v, par);
        }
        else{
            int s1 = find(u, par);
            int s2 = find(v, par);
            if(s1 != s2){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
    }
    return ans;
}