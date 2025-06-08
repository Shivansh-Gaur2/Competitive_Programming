#include <bits/stdc++.h>
using namespace std;

static const int N = 101;       // max number of items
static const int MAX_VAL = 100001; // max sum of values (or a safe upper bound)
static const long long INF = 1e13;

long long w[N], v[N];
bool dp[N][MAX_VAL];
long long minW[N][MAX_VAL];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    // Initialize dp = false; minW = INF
    for(int i = 0; i <= n; i++){
        for(int val = 0; val < MAX_VAL; val++){
            dp[i][val] = false;          // can't achieve that value initially
            minW[i][val] = INF;         // big sentinel for weight
        }
    }

    // Base case: with 0 items, we can achieve value = 0 at weight = 0
    dp[0][0] = true;
    minW[0][0] = 0;

    // Fill DP
    for(int i = 1; i <= n; i++){
        for(int val = 0; val < MAX_VAL; val++){
            // 1) Not take item i
            if (dp[i - 1][val]) {
                dp[i][val] = true;
                minW[i][val] = min(minW[i][val], minW[i - 1][val]);
            }

            // 2) Take item i (only if feasible)
            //    Check if val - v[i] >= 0 (valid index),
            //    dp[i-1][val - v[i]] is true (we can achieve that smaller value),
            //    and total weight won't exceed W.
            if (val - v[i] >= 0 && dp[i - 1][val - v[i]]) {
                long long newWeight = minW[i - 1][val - v[i]] + w[i];
                if (newWeight <= W) {
                    dp[i][val] = true;
                    minW[i][val] = min(minW[i][val], newWeight);
                }
            }
        }
    }

    // The answer: the maximum value `val` that can be achieved with n items
    // under the weight limit W
    int ans = 0;
    for(int val = 0; val < MAX_VAL; val++){
        if (dp[n][val]) {
            ans = val;
        }
    }

    cout << ans << "\n";
    return 0;
}
