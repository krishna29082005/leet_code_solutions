class Solution {
public:
    int f(int i , int j , string &s , string& t , vector<vector<int>>&dp){
        if(j < 0) return 1;
        if(i < 0 && j >= 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            int pick = f(i - 1 , j - 1 , s , t , dp);
            int nonpick = f(i - 1 , j , s , t , dp);
            return dp[i][j] =  pick + nonpick;
        }
        return dp[i][j] = f(i - 1 , j , s , t , dp);
        
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(s.size() , vector<int>(t.size() , -1));
        int ans = f(m - 1 , n - 1 , s , t , dp);
        return ans;
    }
};