class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        

        vector<vector<int>>dp(s.size() + 1 , vector<int>(s2.size() + 1, -1));
        for(int i = 0 ; i < s2.size() + 1 ; i++){
            dp[0][i] = 0;
        }
        for(int i = 0 ; i < s.size() + 1 ; i++){
            dp[i][0] = 0;
        }

        for(int i = 1 ; i < s.size() + 1 ; i++){
            for(int j = 1 ; j < s2.size() + 1 ; j++){
                if(s[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    continue;
                }
                else {
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = max(up , left);
                }
            }
        }
        return dp[s.size()][s2.size()];
    }
};