class Solution {
private:
    int helper(int i , int j , vector<vector<int>>& triangle , int n , 
    vector<vector<int>>&dp){
        if(i == n - 1){
            return dp[i][j] = triangle[i][j];
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        int same = triangle[i][j] + helper(i + 1 , j , triangle , n , dp);
        
        int same1 = triangle[i][j] + helper(i + 1 , j + 1 , triangle , n , dp);
        
        return dp[i][j] = min(same , same1);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       
       int n = triangle.size();
       vector<vector<int>> dp(n , vector<int>(n , INT_MAX));
       return helper(0 , 0 , triangle , n , dp);
    //    dp[0] = triangle[0][0];


    //    for(int i = 1 ; i < n ; i++){
    //     int size = triangle[i].size();
    //     vector<int>temp(n);
    //     for(int j = 0 ; j < size ; j++){
            
    //         int a0 = 1e9;
    //         int a1 = 1e9;
            
    //         if(j >= 0 && j < i){
    //             a0 = triangle[i][j] + dp[j];
    //         }
    //         if(j - 1 >= 0 && j - 1 < i){
    //             a1 = triangle[i][j] + dp[j - 1];
    //         }
    //         temp[j] = min(a0 , a1);
    //     }
    //     dp = temp;
    //    }
    //    int mini = INT_MAX;
    //    for(int i = 0 ; i < n ; i++){
    //     mini = min(mini , dp[i]);
    //    }
    //    return mini;
    }
};