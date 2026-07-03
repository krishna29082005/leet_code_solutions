class Solution {
public:
    
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<unsigned long long>dp(t.size() + 1, 0);
        
        for(int i = 0 ; i < n + 1 ; i++){
            if(i == 0)dp[i] = 1;
            else dp[i] = 0;
        }
        for(int i = 1 ; i < m + 1  ; i++){
        
            for(int j = n ; j >= 1 ; j--){
                if(s[i - 1] == t[j - 1]){
                    dp[j] = dp[j - 1] + dp[j];
                }
                else{
                    dp[j] = dp[j];
                }
            }
        }
        return (int)dp[n];
    }
};