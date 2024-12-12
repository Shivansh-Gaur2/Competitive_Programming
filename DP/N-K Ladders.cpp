#include <iostream>
#include <vector>
using namespace std;

int countWays(int n, int k){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    int ans = 0;

    for(int jump = 1; jump <= k; jump++){
        ans += countWays(n - jump, k);
    }

    return ans;
}

//0(n*k)
int countWaysTD(int n, int k, int *dp){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    if(dp[n] != 0){
        return dp[n];
    }

    int ans = 0;

    for(int jump = 1; jump <= k; jump++){
        ans += countWays(n - jump, k);
    }

    return dp[n] =  ans;
}

//O(n*k)
int countWaysBU(int n, int k){
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n ; i++){
        for(int jump =1 ; jump <= k; jump++){
            if(i- jump >= 0){
                dp[i] += dp[i - jump];
            }
        }
    }
    return dp[n];
}

//Bottom Up - Optimised ((O(n+k)))
int countWaysOpt(int n , int k){
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= k ; i++){
        dp[i]   = 2*dp[i - 1];
    }
    for(int i = k + 1; i <= n; i++){
        dp[i] = 2*dp[i - 1] - dp[i - k - 1];
    }

    return dp[n];
}

int main(){
    int n , k;
    cin >> n >> k;
    int dp[1000] = {0};
    cout << countWaysTD(n, k, dp) << endl;
    cout << countWays(n, k) << endl;

    return 0;
}