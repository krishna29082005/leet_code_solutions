class Solution {
private: 
    int ways(int n , vector<int>&dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = ways(n - 1 , dp) + ways(n - 2 , dp);
    }
public:
    int climbStairs(int n) {
       vector<int>dp(n + 1 , -1);
       int ans = ways(n , dp);
       return ans; 
    }
};