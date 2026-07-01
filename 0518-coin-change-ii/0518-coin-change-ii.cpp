class Solution {
public:
    int f(int index , int target , vector<int>& coins , vector<vector<int>>&dp){
        if(target == 0) return 1;
        if(index == coins.size()) return 0;

        if(dp[index][target] != -1) return dp[index][target];

        int pick = 0;
        if(target >= coins[index]){
            pick = f(index , target - coins[index] , coins , dp);
        }
        int nonpick = f(index + 1 , target , coins , dp);
        
        return dp[index][target] = pick + nonpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(coins.size() , vector<int>(amount + 1 , -1));
        int ans = f(0 , amount , coins , dp);
        return ans;
    }
};