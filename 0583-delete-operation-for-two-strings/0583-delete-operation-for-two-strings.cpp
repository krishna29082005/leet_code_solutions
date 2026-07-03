class Solution {
public:
    int f(int i , int j , string& s1 , string & s2 , vector<vector<int>>&dp){

        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        if(s1[i] == s2[j]) return dp[i][j] = 1 + f(i - 1 , j - 1 , s1 , s2 , dp);
        
        int a = f(i - 1 , j , s1 , s2 , dp);
        int b = f(i , j - 1 , s1 , s2 , dp);
        return dp[i][j] = max(a , b);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() , vector<int>(word2.size() , -1));
        int ans = f(word1.size() - 1 , word2.size() - 1  , word1 , word2 , dp);
        int ans1 = word1.size() - ans;
        int ans2 = word2.size() - ans;
        return ans1 + ans2;
    }
};