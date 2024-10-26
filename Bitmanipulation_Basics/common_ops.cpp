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

int main(){
    int n = 5;
    int i; 
    cin >> i;

    // cout << getIthBit(n, i) << endl;
    // clearIthBit(n, i);
    // setIthBit(n, i);
    updateIthBit(n, i, 1);
    cout << n << endl;

}