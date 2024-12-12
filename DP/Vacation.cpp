#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5; 
int a[N][3] , dp[N][3];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3 ; j++){
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i = 1; i < n; i++){
        dp[i][0] = a[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    // for (int i = 1; i < n; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		for (int jj = 0; jj < 3; jj++) {
	// 			if (j != jj) {
	// 				dp[i][j] = max(dp[i][j], dp[i - 1][jj] + a[i][j]);
	// 			}
	// 		}
	// 	}
	// }

    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    return 0;
}