class Solution {
private: 
    int f(int i , int j , vector<vector<int>>&dp , int m , int n){
        if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int up = 0;
        int left = 0;
        if(i - 1 >= 0 && i - 1 < m) // going up
        {
            up = f(i - 1 , j , dp , m , n);
        }
        
        if(j - 1 >= 0 && j - 1 < n) // going left
        {
            left = f(i , j - 1 , dp , m , n);
        }
        return dp[i][j] = up + left;
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n , -1));
        if(m == 1 && n == 1) return 1;
        return f(m - 1 , n - 1 , dp , m , n);
    }
};