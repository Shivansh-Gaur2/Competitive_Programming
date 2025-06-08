#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n, m, k;
	    cin >> n >> m >> k;
	    
	    int ans = INT_MAX;
	    
	    for(int i = 1; i <= n ; i++){
	        for(int j = 1; j <= m ; j++){
	            int per = 2 * (i+ j);
	            if(per > 100){
	                break;
	            }
	            else{
                cout << i << " " << j  << " " << per << endl;
	                ans = min(ans, abs(k - per));
	            }
	        }
	    }
	    cout << ans << endl;
	}

    return 0;

}
