class Solution {
    private:
    int f(int i , int j , string& s , string& t , vector<vector<int>>&dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            int pick = f(i + 1 , j + 1 , s , t , dp);
            int nonpick = f(i + 1 , j , s , t , dp);
            return dp[i][j] = pick + nonpick;
        }
        return dp[i][j] = f(i + 1 , j , s , t , dp);
    }
public:
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return f(0 , 0 , s , t , dp);
    }
};