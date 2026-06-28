class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n , -1);
        if(m == 1 && n == 1) return grid[0][0];
        dp[0] = grid[0][0];
        for(int i = 0 ; i < m ; i++){
            vector<int>temp(n , -1);
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) 
                {
                    temp[j] = grid[0][0];
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i - 1 < 0) up = 1e9;
                else up = dp[j];

                if(j - 1 < 0) left = 1e9;
                else left = temp[j - 1];

                temp[j] = grid[i][j] + min(up , left);
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};