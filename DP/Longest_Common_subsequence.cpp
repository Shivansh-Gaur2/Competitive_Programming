#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string text1, text2;
        cin >> text1 >> text2;

    int n = text1.size(); 
    int m = text2.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1 , 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    }
    return 0;
};
