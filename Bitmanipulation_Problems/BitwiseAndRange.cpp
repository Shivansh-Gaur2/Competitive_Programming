// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
// Constraints:
// 0 <= left <= right <= 2^31 - 1
// Example 1:
// Input: left = 5, right = 7
// Output: 4

#include<bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int ans = 0;
    for(int i = 31; i>=0 ; i--){
        int pow = 1LL << i;
        int bitL = (left & pow) > 0, bitR = (right& pow) > 0;
        
        
        if(bitL == bitR){
            ans += bitL*pow;
        }
        else{
            break;
        }
        
    }
    return ans;
}

int main(){
    int left, right;
    cin >> left >> right;
    cout << rangeBitwiseAnd(left, right) << endl;
    return 0;
}