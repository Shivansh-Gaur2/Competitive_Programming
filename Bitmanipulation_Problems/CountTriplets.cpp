#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// int countTriplets(vector<int> nums){
//     int n = nums.size();
//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             for(int k = 0; k < n; k++){
//                 if((nums[i] & nums[j] & nums[k]) == 0){
//                     ans++;
//                 }
//             }
//         }
//     }
//     return ans;
// }

int countTriplets(vector<int> nums) {
    int n = nums.size();
    unordered_map<int, int> ump;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ump[nums[i] & nums[j]]++;
        }
    }
    
    int ans = 0;
    for(auto it : ump){
        for(int i = 0 ; i < nums.size(); i++){
            if((nums[i] & it.first) == 0){
                ans += it.second;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2, 1, 3};

    cout << countTriplets(nums) << endl;
}