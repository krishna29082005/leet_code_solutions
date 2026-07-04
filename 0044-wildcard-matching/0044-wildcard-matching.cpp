class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<bool>dp(n + 1, false);
        dp[0] = true;
        
        for(int i = 1 ; i < n + 1 ; i++){
           if(p[i - 1] == '*')
              dp[i] = dp[i - 1];
           else
              dp[i] = false;
        }

        for(int i = 1 ; i < m + 1 ; i++){
            vector<bool>temp(n + 1, false);
            temp[0] = false;
            for(int j = 1 ; j < n + 1 ; j++){
                if(s[i - 1] == p[j - 1]){
                   temp[j] = dp[j - 1];
                }
                if(p[j - 1] == '?'){
                   temp[j] = dp[ j - 1];
                }

                if(p[j - 1] == '*'){
                   temp[j] = dp[j] || temp[j - 1];
                } 
            }
            dp = temp;
        }
        return dp[n];
    }
};