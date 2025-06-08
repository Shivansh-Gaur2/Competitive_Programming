#include <bits/stdc++.h>
using namespace std;

#define ld long double
const int N = 3000;

ld p[N];
int n;

ld dp(int i, int h, int t){
    ld ans = 0;
    if(h){
        ans += dp(i+1, h-1 ,t) * p[i];
    }
    if(t){
        ans += dp(i+1, h, t-1) * (1.00 - p[i]);
    }
    return ans;
}

int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    ld ans= 0;
    for(int i = (n/2 + 1); i <= n; i++){
        ans += dp(0, i, n-i);
    }

    cout << setprecision(10) << fixed;
    cout << ans;

    return 0;
}