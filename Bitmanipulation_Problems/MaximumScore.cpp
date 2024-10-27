#include <iostream>
#include <vector>
using namespace std;

int matrixScore(vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();
 
    // Flip rows whose first column is 0
    for(int i = 0 ; i < n ; i++){
        if(grid[i][0] == 0){
            for(int j = 0 ; j < m ; j++){
                grid[i][j] ^= 1;   // Toggles the value using XOR
            }
        }
    }
 
    // The contribution of the first column to the final score 
    // is always n * 2^(m-1), since all rows will start with 1.
    int ans = (1<<(m-1))*n;
 
    // For other columns, maximize the number of 1s
    for(int j = 1 ; j < m ; j++){
        int count = 0;
        for(int i = 0 ; i < n; i++){
            count += grid[i][j];
        }
 
        ans += (1<<(m-j-1))*max(count, n - count); // Tallying the score contribution for each column
    }
    return ans;
}

// int matrixScore(vector<vector<int>>&grid){
//     int n = grid.size();
//     int m = grid[0].size();

//     for(int i = 0; i < n; i++){
//         if(grid[i][0] == 0){
//             for(int j = 0; j < m; j++){
//                 grid[i][j] = 1 - grid[i][j];
//             }
//         }
//     }

//     for(int j = 1 ; j < m ; j++){
//         int cnt = 0;
//         for(int i = 0; i < n; i++){
//             if(grid[i][j] ==1){
//                 cnt++;
//             }

//         }
//         if(cnt < (n+1)/2){
//             for(int i = 0; i < n; i++){
//                 grid[i][j] = 1 - grid[i][j];
//             }
//         }
//     }

//     int maxScore = 0;
//     for(int i = 0; i < n; i++){
//         int rowScore = 0;
//         for(int j = 0 ; j < m; j++){
//             rowScore = rowScore * 2 + grid[i][j];
//         }
//         maxScore += rowScore;
//     }
//     return maxScore;
// }

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>>grid(n , vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << matrixScore(grid) << endl;

    return 0;
}