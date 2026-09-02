class Solution {
private: 
    int helper(int m  , int n , vector<vector<int>>& dp){
        if(m == 0 && n == 0) return dp[m][n] = 1;
         
        if(dp[m][n] != -1) return dp[m][n];

        int up = 0;
        if(m - 1 >= 0){
           up = helper(m - 1 , n , dp);
        }

        int left = 0;
        if(n - 1 >= 0){
           left = helper(m , n - 1 , dp);
        }
        return dp[m][n] = left + up;
    }
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m , vector<int>(n , -1));
     return helper(m - 1 , n - 1 , dp);   
    }
};