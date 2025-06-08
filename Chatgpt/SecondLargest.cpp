#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define debug(x) cerr << #x << " = " << (x) << endl;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];

    int lar = INT_MIN, slar = INT_MIN;

    rep(i, 0, n){
        if(arr[i] > lar){
            slar = lar;  // ✅ Store previous largest before updating
            lar = arr[i];
        }
        else if(arr[i] > slar && arr[i] != lar){
            slar = arr[i];
        }
    }

    if (slar == INT_MIN) cout << "No second largest element\n";  // Handle edge case
    else cout << slar << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
