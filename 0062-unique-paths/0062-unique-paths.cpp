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
     dp[0][0] = 1;
     for(int i = 0 ; i < m ; i++)
     {
        for(int j = 0 ; j < n ; j++){
            if(i == 0 &&j == 0) continue;

            int up = 0;
            int left = 0;
            if(i - 1 >= 0){
                up = dp[i - 1][j];
            }
            if(j - 1 >= 0){
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
     }
     return dp[m - 1][n - 1];   
    }
};