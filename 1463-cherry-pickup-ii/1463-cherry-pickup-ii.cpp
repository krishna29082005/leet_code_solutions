class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(
                             m ,  
                             vector<vector<int>>( 
                             n,  
                             vector<int>(n , -1)));
    
        
        for(int col1 = 0; col1 < n; col1++) {
            for(int col2 = 0; col2 < n; col2++) {

            if(col1 == col2)
               dp[m-1][col1][col2] = grid[m-1][col1];
            else
               dp[m-1][col1][col2] = grid[m-1][col1] + grid[m-1][col2];
        }
    }
        
    for(int row = m - 2 ; row >=0 ; row--){
       for(int col1 = 0; col1 < n; col1++) {
          for(int col2 = 0; col2 < n; col2++) {
                int maxi = INT_MIN;
                int reward = 0;
                if(col1 == col2)
                   reward = grid[row][col1];
                else
                   reward = grid[row][col1] + grid[row][col2];

        for(int d1 = -1 ; d1 < 2 ; d1++){
            for(int d2 = -1 ; d2 < 2 ; d2++){
                int newcol1 = col1 + d1;
                int newcol2 = col2 + d2;
                int nextreward = 0;
                if(newcol1 >= 0 && newcol1 < n && newcol2 >= 0 && newcol2< n)
                    {
                        nextreward = dp[row + 1][newcol1][newcol2];
                        int totalreward = reward + nextreward;
                        maxi = max(maxi , totalreward);
                    }
                }
            }
            dp[row][col1][col2] = maxi;
        }
    }
    }
    return dp[0][0][n - 1];
    }
    
};