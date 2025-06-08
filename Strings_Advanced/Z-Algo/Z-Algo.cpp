#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define debug(x) cerr << #x << " = " << (x) << endl;

vector<int> computeZArray(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);

        while(i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;

        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
void solve() {
    string text, pattern;
    cin >> text >> pattern;
    string concat = pattern + "$" + text;
    vector<int> z = computeZArray(concat);

    int m = pattern.size();
    for(int i = m + 1; i < z.size(); i++){
        if(z[i] == m) cout << i - m + 1 << " ";
    }
    cout << endl;
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