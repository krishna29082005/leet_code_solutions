class Solution {
private:
   int helper(int m  , int n , vector<vector<int>>& dp , vector<vector<int>>& grid){
        if(m == 0 && n == 0) return dp[m][n] = grid[m][n];
         
        if(dp[m][n] != -1) return dp[m][n];

        int up = 1e9;
        if(m - 1 >= 0){
           up = grid[m][n] + helper(m - 1 , n , dp , grid);
        }

        int left = 1e9;
        if(n - 1 >= 0){
           left = grid[m][n] + helper(m , n - 1 , dp , grid);
        }
        return dp[m][n] = min(up , left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(n == 0 && m == 0) return 0;
        
        vector<vector<int>> dp(m , vector<int>(n , -1));
        
        return helper(m - 1 , n  - 1, dp , grid);
    }
};