class Solution {
    private:
    int helper(int target , vector<int>&coins , vector<int>&dp){
        if(target == 0) return 0;

        if(dp[target] != INT_MAX) return dp[target];
        int mini = 1e9;

        for(int i = 0 ; i < coins.size() ; i++){
            if(target >= coins[i]){

                int ans = helper(target - coins[i] , coins , dp);
                if(ans == -1) continue;
                mini = min(mini , ans + 1);

            }
        }
        if(mini == 1e9) return dp[target] = -1;
        return dp[target] = mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1 , INT_MAX);
        return helper(amount , coins , dp);
    }
};