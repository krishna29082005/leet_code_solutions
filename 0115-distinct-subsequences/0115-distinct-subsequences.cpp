class Solution {
public:
    
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<unsigned long long>>dp(s.size() + 1, vector<unsigned long long>(t.size() + 1, -1));
        for(int i = 0 ; i < m + 1 ; i++){
            dp[i][0] = 1;
        }
        for(int i = 1 ; i < n + 1 ; i++){
            dp[0][i] = 0;
        }
        for(int i = 1 ; i < m + 1  ; i++){
            for(int j = 1 ; j < n + 1 ; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
};