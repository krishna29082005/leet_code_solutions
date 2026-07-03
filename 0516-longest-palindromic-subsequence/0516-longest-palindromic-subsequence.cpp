class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        

        vector<int>dp(s2.size() + 1, 0);
        for(int i = 0 ; i < s2.size() + 1 ; i++){
            dp[i] = 0;
        }

        for(int i = 1 ; i < s.size() + 1 ; i++){
            vector<int>temp(s2.size() + 1 , 0);
            for(int j = 1 ; j < s2.size() + 1 ; j++){
                if(s[i - 1] == s2[j - 1]){
                    temp[j] = 1 + dp[j - 1];
                    continue;
                }
                else {
                int up = dp[j];
                int left = temp[j - 1];
                temp[j] = max(up , left);
                }
            }
            dp = temp;
        }
        return dp[s2.size()];
    }
};