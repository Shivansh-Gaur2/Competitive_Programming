#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define debug(x) cerr << #x << " = " << (x) << endl;

#define d 256

vector<int> rabinKarp(string text, string pattern, int q) {
    int n = text.size(), m = pattern.size();
    vector<int> result;
    int pHash = 0, tHash = 0, h = 1;

    // Compute h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++) 
        h = (h * d) % q;

    // Compute initial hashes for pattern and first window of text
    for (int i = 0; i < m; i++) {
        pHash = (pHash * d + pattern[i]) % q;
        tHash = (tHash * d + text[i]) % q;
    }

    // Slide over text
    for (int i = 0; i <= n - m; i++) {
        // Check if hash matches
        if (tHash == pHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) result.pb(i);
        }

        // Compute next window hash using Rolling Hash
        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h % q) + text[i + m]) % q;
            if (tHash < 0) tHash += q; // Fix negative hash values
        }
    }
    return result;
}

void solve() {
    string text, pattern;
    cin >> text >> pattern;
    int prime = 101;
    vector<int> occurances = rabinKarp(text, pattern, prime);

    // Output results
    if (occurances.empty()) cout << "Pattern not found\n";
    else {
        cout << "Pattern found at indices: ";
        for (int idx : occurances) cout << idx << " ";
        cout << endl;
    }
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
