#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;


    if(n & (n-1) == 0){
        cout << "Power of 2" << endl;
    }
    else{
        cout << "Not a power of 2" << endl;
    }

    return 0;
}