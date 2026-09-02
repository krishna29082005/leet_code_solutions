class Solution {
private:
   int helper(int m  , int n , vector<vector<int>>&grid , vector<vector<int>>& dp){
        if(m == 0 && n == 0) return dp[m][n] = 1;
        if(grid[m][n] == 1) return dp[m][n] = 0;

        if(dp[m][n] != -1) return dp[m][n];

        int up = 0;
        if(m - 1 >= 0){
           up = helper(m - 1 , n , grid , dp);
        }

        int left = 0;
        if(n - 1 >= 0){
           left = helper(m , n - 1 , grid , dp);
        }
        return dp[m][n] = left + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m , vector<int>(n , -1));
        if (obstacleGrid[0][0] == 1)
           return 0;
       
        
        return helper(m - 1 , n - 1 , obstacleGrid , dp);
    }
};