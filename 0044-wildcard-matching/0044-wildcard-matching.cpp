class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>>dp(m + 1 , vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1 ; i < m + 1 ; i++){
            dp[i][0] = false;
        }
        
        for(int i = 1 ; i < n + 1 ; i++){
           if(p[i - 1] == '*')
              dp[0][i] = dp[0][i - 1];
           else
              dp[0][i] = false;
        }

        for(int i = 1 ; i < m + 1 ; i++){
            for(int j = 1 ; j < n + 1 ; j++){
                if(s[i - 1] == p[j - 1]){
                   dp[i][j] = dp[i - 1][j - 1];
                }
                if(p[j - 1] == '?'){
                   dp[i][j] = dp[i - 1][ j - 1];
                }

                if(p[j - 1] == '*'){
                   dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } 
            }
        }
        return dp[m][n];
    }
};