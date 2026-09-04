class Solution {
public:
    int helper(int i , int target , vector<int>&coins , vector<vector<int>>&dp){
        if(target < 0) return 0;

        if(i == coins.size()){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];
        
        int pick = helper(i , target - coins[i] , coins , dp);
        
        int nonpick = helper(i + 1, target , coins , dp);

        return dp[i][target] = pick + nonpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size() , vector<int>(amount + 1 , -1));
        int ans = helper(0 , amount , coins , dp);
        return ans;
    }
};