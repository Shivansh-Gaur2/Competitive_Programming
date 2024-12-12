// Problem Statement
// There are 
// N items, numbered 
// 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi.

// Taro has decided to choose some of the 
// N items and carry them home in a knapsack. The capacity of the knapsack is 
// W, which means that the sum of the weights of items taken must be at most 
// W.

// Find the maximum possible sum of the values of items that Taro takes home.

// Constraints
// All values in input are integers.
// 1≤N≤100
// 1≤W≤10^5
// 1≤wi ≤W
// 1≤vi <=10^9

#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 100;

int v[N], w[N], W, n, memo[N][100001];

//it returns the maximum value total value
int knapsack(int index, int weight){
    if(index >= n) return 0;
    //memoization
    int &ans = memo[index][weight];

    if(ans != -1) return ans;
    //do not take the item
    ans = knapsack(index + 1, weight);
    //take the item at index
    if(w[index] + weight <= W){
        ans = max(ans, v[index] + knapsack(index + 1, weight + w[index]));
    }
    return ans;
}

int32_t main(){
    cin >> n >> W;

    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }

	memset(memo, -1, sizeof(memo));

    cout << knapsack(0, 0);

    return 0;
}