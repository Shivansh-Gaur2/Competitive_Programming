#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        int totalCycle = a + b + c;
        int days = 0;

        if (totalCycle > 0) {
            int fullCycles = n / totalCycle;
            days = fullCycles * 3;
            int remaining = n % totalCycle;

            if (remaining > 0) {
                if (remaining <= a) {
                    days += 1;
                } else if (remaining <= a + b) {
                    days += 2;
                } else {
                    days += 3;
                }
            }
        } else if (a == 0 && b == 0 && c == 0) {
            cout << "Impossible" << endl;
            continue;
        }

        cout << days << endl;
    }
    return 0;
}
