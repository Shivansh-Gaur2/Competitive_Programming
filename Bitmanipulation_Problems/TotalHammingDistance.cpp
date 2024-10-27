#include<bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int> nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < 32; ++i) {  
        int countOnes = 0;
        for (int num : nums) {
            if (num & (1 << i)) {  
                countOnes++;
            }
        }
        ans += countOnes * (n - countOnes); 
    }
    return ans;
}
    
int main(){
    vector<int> nums = {4, 14, 2};
    cout << totalHammingDistance(nums) << endl;
    return 0;
}