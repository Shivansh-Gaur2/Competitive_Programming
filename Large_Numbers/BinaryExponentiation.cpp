#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int mod = 1e9 + 7;

int powr(int a, int b) {
    int res = 1;
    a = a % mod; // Ensure a is within the mod range
    while (b > 0) { // Loop until b is greater than 0
        if (b & 1) { // If b is odd
            res = (res * a) % mod; // Modular multiplication
        }
        a = (a * a) % mod; // Square a and take modulo
        b /= 2; // Halve b
    }
    return res;
}

int32_t main() {
    int a, b;
    cin >> a >> b; // Input the base and exponent

    cout << powr(a, b) << endl; // Output the result
    
    return 0;
}
