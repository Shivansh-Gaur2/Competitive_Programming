#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n , k;
    cin >> n >> k;

    int h[n];

    for(int i = 0 ; i < n; i++){
        cin >> h[i];
    }

    int dp[n];
    dp[0] = 0; 
    dp[1] = abs(h[1] - h[0]);

    for(int i = 2; i < n; i++){
        dp[i] = INT_MAX;
        for(int kk = 1; kk <= k && i - kk >= 0; kk++){
            dp[i] = min(dp[i], dp[i-kk] + abs(h[i] - h[i-kk]));
        }
    }

    cout << dp[n-1];
    
    return 0;
}