class Solution {
private:
    int helper(int row , int col1 , int col2 , vector<vector<int>>&grid
     , vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return -1e9;

        if(row == n - 1){
            if(col1 == col2){
                return dp[row][col1][col2] = grid[row][col1];
            }
            else{
                return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
            }
        }
        
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int reward = 0;

        if(col1 == col2){
            reward = grid[row][col1];
        }else{
            reward = grid[row][col1] + grid[row][col2];
        }
        
        int maxi = INT_MIN;
        for(int i = -1 ; i < 2 ; i++)
        {
            int nc1 = col1 + i;
            for(int j = -1 ; j < 2 ; j++){
                int nc2 = col2 + j;
                if(nc1 >= 0 && nc1 < m && nc2 >=0 && nc2 < m){
                    int nextreward = helper(row + 1 , nc1 , nc2 , grid ,dp);
                    int totalreward = reward + nextreward;
                    maxi = max(maxi , totalreward);
                }
            }
        }
        return dp[row][col1][col2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m , -1)));
        
        for(int col1 = 0 ; col1 < m ; col1++){
            for(int col2 = 0 ; col2 < m ; col2++){
                if(col1 == col2){
                    dp[n - 1][col1][col2] = grid[n - 1][col2];
                }else{
                    dp[n - 1][col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
                }
            }
        }

        for(int row = n - 2 ; row >= 0 ; row--){
            for(int col1 = 0 ; col1 < m ; col1++){
                for(int col2 = 0 ; col2 < m ; col2++){
                    int reward = 0;
                    int maxi = INT_MIN;

                    if(col1 == col2){
                        reward = grid[row][col1];
                    }else{
                        reward = grid[row][col1] + grid[row][col2];
                    }

                    for(int i = -1 ; i < 2 ; i++){
                        int nc1 = col1 + i;
                        for(int j = -1 ; j < 2 ; j++){
                            int nc2 = col2 + j;
                            if(nc1 >= 0 && nc1 < m && nc2 >= 0 && nc2 < m){
                                int nextreward = dp[row + 1][nc1][nc2];
                                int total = reward + nextreward;
                                maxi = max(maxi , total);
                            }
                        }
                    }
                    dp[row][col1][col2] = maxi;
                }
            }
        }
        
        return dp[0][0][m - 1];
    } 
};