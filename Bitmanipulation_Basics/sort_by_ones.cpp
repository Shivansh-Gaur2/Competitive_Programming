#include<bits/stdc++.h>
using namespace std;
 
bool cmp(int &a, int &b) {
    int setA = __builtin_popcount(a);  
    int setB = __builtin_popcount(b);  
 
    if(setA == setB) {
        return a < b;   
    }
    return setA < setB;  
}

// My solution 
// vector<int> sortByBits(vector<int> arr) {
//  sort(arr.begin(), arr.end(), [](int a, int b) {
//         int cnt_a = 0, cnt_b = 0;
        
//         int temp_a = a;
//         while (temp_a > 0) {
//             temp_a = temp_a & (temp_a - 1);
//             cnt_a++;
//         }
        
//         int temp_b = b;
//         while (temp_b > 0) {
//             temp_b = temp_b & (temp_b - 1);
//             cnt_b++;
//         }
        
//         if (cnt_a != cnt_b) {
//             return cnt_a < cnt_b;
//         } else {
//             return a < b;
//         }
//     });
//     return arr;
// }
 
vector<int> sortByBits(vector<int> arr) {
    sort(arr.begin(), arr.end(), cmp); 
    return arr;
}