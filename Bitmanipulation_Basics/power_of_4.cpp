#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;

    if(n & (n-1) == 0 && n & 0x55555555){
        cout << "Power of 4" << endl;
    }
    else{
        cout << "Not a power of 4" << endl;
    }
}