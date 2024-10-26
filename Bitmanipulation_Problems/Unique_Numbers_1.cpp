#include <iostream>
#include <vector>
using namespace std;

int uniqueNo(vector<int> arr){
    int n = arr.size();
    int cummilative_xor = 0;

    for(int i = 0; i < n; i++){
        cummilative_xor = cummilative_xor ^ arr[i];
    }
    return cummilative_xor;
}

int main(){
    vector<int> arr = {1, 3, 5, 4, 3, 1, 5};

    cout << uniqueNo(arr) << endl;
}