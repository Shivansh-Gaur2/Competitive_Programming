#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int cnt = 0;
    int xorVal = x ^ y;
    
    cnt = __builtin_popcount(xorVal);
    return cnt;
}

int hammingDistance(int x, int y){
    int cnt = 0;
    int xorVal = x ^ y;
    while(xorVal > 0){
        xorVal = xorVal & (xorVal-1);
        cnt++;
    }
    return cnt;

}

int hammingDistance(int x, int y) {
    int xorResult = x ^ y;
    int distance = 0;
    while (xorResult) {
        distance += xorResult & 1;
        xorResult >>= 1;
    }
    return distance;
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << hammingDistance(x, y) << endl;
    return 0;
}