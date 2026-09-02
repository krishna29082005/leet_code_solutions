class Solution {
private:
    int helper(int i , int j , vector<vector<int>>& triangle , int n , 
    vector<vector<int>>&dp){
        if(i == n - 1){
            return dp[i][j] = triangle[i][j];
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int same = triangle[i][j] + helper(i + 1 , j , triangle , n , dp);
        int same1 = 1e9;
        if(j + 1 <= i + 1){
            same1 = triangle[i][j] + helper(i + 1 , j + 1 , triangle , n , dp);
        }
        return dp[i][j] = min(same , same1);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       
       int n = triangle.size();
       vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
       return helper(0 , 0 , triangle , n , dp);
    }
};