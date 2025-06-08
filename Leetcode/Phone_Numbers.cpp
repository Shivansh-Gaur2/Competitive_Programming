#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> letters = {"", "" , "abc", "def" , "ghi" , "jkl", "mno", "pqrs" , "tuv" , "wxyz"};

        queue<string> q;
        q.push("");
        vector<string> ans;

        for(char digit : digits){
            int n = q.size();
            string let = letters[digit - '0'];

            while(n--){
                string top = q.front();
                q.pop();
                for(char letter : let){
                    q.push(top + letter);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for(string str : ans){
        cout << str << endl;
    }
    return 0;
}