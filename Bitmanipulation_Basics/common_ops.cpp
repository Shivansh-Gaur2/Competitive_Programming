#include <iostream>
using namespace std;

int getIthBit(int n, int i){
    int mask = 1 << i;
    return (n & mask) > 0 ? 1 : 0;
}

void clearIthBit(int& n , int i){
     int mask = ~(1 << i);
     n = n & mask;
}

void setIthBit(int& n, int i){
    int mask = 1 << i;
    n = n | mask;
}

void updateIthBit(int &n, int i, int v){
    int mask = ~(1 << i);
    n = n & mask;
    int mask2 = v << i;
    n = n | mask2;
}

int clearLastIBits(int n, int i){
    int mask = (-1 << i);
    return n & mask;
}

void clearLastIthBits(int &n, int i){
    int mask = (-1 << i);
    n = n& mask;
}

int clearRangeItoJ(int n, int i, int j){
    int ones = (~0);
    int a = ones << (j+1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int main(){
    int n = 31;
    int i; 
    cin >> i;

    // cout << getIthBit(n, i) << endl;
    // clearIthBit(n, i);
    // setIthBit(n, i);
    // updateIthBit(n, i, 1);
    clearRangeItoJ(n, 1, 2);
    cout << n << endl;

}