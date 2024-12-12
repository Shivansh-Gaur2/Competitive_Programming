#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int h[N], memo[N];

int dp(int n){
    if(n == 0){
        return 0;
    }
    int &ans = memo[n];
    if(ans != -1){
        return ans;
    }
    ans = abs(h[n] - h[n-1]) + dp(n-1);
    if(n-2 >= 0){
        ans = min(ans, abs(h[n] - h[n-2]) + dp(n-2));
    }

    return ans;
}

int32_t main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    memset(memo, -1, sizeof(memo));

    return 0;
}