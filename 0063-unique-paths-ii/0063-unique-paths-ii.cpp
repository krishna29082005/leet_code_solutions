class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int>dp(n , -1);
        if(m == 1 && n == 1 && obstacleGrid[0][0] != 1) return 1;
        dp[0] = 1;
        for(int i = 0 ; i < m ; i++){
            vector<int> temp(n);
            for(int j = 0 ; j < n ; j++){

                if(obstacleGrid[i][j] == 1) continue;

                if(i == 0 && j == 0) 
                {
                    temp[j] = 1;
                    continue;
                }
                
                int up = 0;
                int left = 0;
                if(i - 1 >= 0 && i - 1 < m && obstacleGrid[i-1][j] != 1) // going up
                {
                    up = dp[j];
                }
               if(j - 1 >= 0 && j - 1 < n && obstacleGrid[i][j-1] != 1) // going left
                {
                    left = temp[j - 1];
                } 
                temp[j] = up + left;
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};