class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        if(m == 1 && n == 1) return grid[0][0];
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) continue;
                
                int up = 0;
                int left = 0;
                if(i - 1 < 0) up = 1e9;
                else up = dp[i - 1][j];

                if(j - 1 < 0) left = 1e9;
                else left = dp[i][j - 1];

                dp[i][j] = grid[i][j] + min(up , left);
            }
        }
        return dp[m - 1][n - 1];
    }
};