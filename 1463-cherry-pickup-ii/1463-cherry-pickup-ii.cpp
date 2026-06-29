class Solution {
private:
    int f(int row , int col1 , int col2 , vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp ){

        int m = grid.size();
        int n = grid[0].size();

        if(col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
        return -1e9;//boundary;
        
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];//dp;
        
        if(row == m - 1){//base case
            if(col1 == col2) return dp[row][col1][col2] = grid[row][col1];
            else
            return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
        }
        
        
        int reward = 0;
        if(col1 == col2) //collecting current reward
           reward = grid[row][col1];
        else {
            reward = grid[row][col1] + grid[row][col2];
        }

        int dc[3] = {-1 , 0 , 1};//collecting max of all the 9 combinations
        int dc2[3] = {-1 , 0 , 1};
        
        int maxi = INT_MIN;
        for(int i = 0 ; i < 3 ; i++){
            int nc1 = col1 + dc[i];
            for(int j = 0 ; j < 3 ; j++){
                int nc2 = col2 + dc2[j];
                if(nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n){
                    int nextreward = f(row + 1 , nc1 , nc2 , grid , dp);
                    int totalreward = reward + nextreward;
                    maxi = max(maxi , totalreward);
            }       
        }
        }
        return dp[row][col1][col2] = maxi;
}
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(
                             m ,  
                             vector<vector<int>>( 
                             n,  
                             vector<int>(n , -1)));

        
        int ans = f(0 , 0 , n - 1 , grid , dp);
        return ans;
    }
    
};