#include<bits/stdc++.h>
using namespace std;
 
int solve(int n) {
    int ans = 0, curr = 0;
    while (n > 0) {
        if (n & 1) {
            curr++;
        } else {
            ans = max(ans, curr);
            curr = 0;
        }
        n >>= 1;
    }
    return max(ans, curr);
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}