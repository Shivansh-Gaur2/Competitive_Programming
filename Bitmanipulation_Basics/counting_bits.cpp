#include <iostream>
using namespace std;


int count_bits(int n){
    int cnt = 0;

    while(n > 0){
        int last_bit = (n&1);
        cnt += last_bit;

        n = n >> 1;
    }

    return cnt;
}

int count_bits_hack(int n){
    int ans = 0;

    while(n > 0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    cout << count_bits(n) << endl;

    return 0;
}