class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount + 1 , 1e9);
        dp[0] = 0;
        for(int i = 1 ; i < amount + 1 ; i++){
            
            int mini = 1e9;
            for(int j = 0 ; j < coins.size() ; j++){  

                if(i >= coins[j]){
                   int ans = dp[i - coins[j]];
                   mini = min(mini , ans + 1);
                }
            }
            dp[i] = mini; 
        }
        if(dp[amount] == 1e9) return -1;
        return dp[amount];
    }
};