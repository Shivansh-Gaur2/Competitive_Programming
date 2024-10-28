#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        arr[0] %= n;
        for(int i = 1; i < n; i++){
            arr[i] = (arr[i] + arr[i-1])%n;
        }

        int start = -1, end = -1;
        map<int, int> index;

        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                start = 1;
                end = i+1;
                break;
            }
            if(index[arr[i]] > 0){
                start = index[arr[i]] + 1;
                end = i+1;
                break;
            }
            index[arr[i]] = i+1;
        }

        cout << end - start + 1 << endl;
        for (int i = start; i <= end; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}