// Unique Numbers - Given 2N + 2 numbers, where 
// every number is coming twice except two numbers 
// find those two unique numbers

#include <iostream>
#include <vector>
using namespace std;

void uniqueNo2(vector<int> arr){
    int n= arr.size();

    int result = 0;
    for(int i = 0; i < n; i++){
        result = result ^ arr[i];
    }

    int pos = 0;
    int temp = result;
    while((temp&1) != 1){
        pos++;
        temp = temp >> 1;
    }

    int setA = 0;
    int setB = 0;
    int mask = (1 << pos);

    for(int i = 0; i < n; i++){
        if((arr[i] & mask) > 0){
            setA = setA ^ arr[i];
        }
        else{
            setB = setB ^ arr[i];
        }
    }
    cout << setA << endl;
    cout << setB << endl;
}

int main(){
    vector<int> arr = {2, 3, 4, 5, 4, 3, 7 ,2};
    uniqueNo2(arr);

}