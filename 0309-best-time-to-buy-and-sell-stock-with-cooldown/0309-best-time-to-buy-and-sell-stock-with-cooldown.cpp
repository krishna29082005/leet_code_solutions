class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n + 2 , vector<int>(2 , -1));
        for(int i = 0 ; i < 2 ; i++){
            dp[n + 1][i] = 0;
            dp[n][i] = 0;
        }
        for(int i = n - 1 ; i >= 0  ; i--){
            for(int j = 0 ; j < 2 ; j++){
                if(j == 1){
                    int buy = -prices[i] + dp[i + 1][0];
                    int nbuy = dp[i + 1][1];
                    dp[i][j] = max(buy , nbuy);
                }
                else{
                    int sell = prices[i] +  dp[i + 2][1];
                    int nsell = 0 + dp[i + 1][0];
                    dp[i][j] = max(sell , nsell);
                }
            }
        }
        return dp[0][1];
    }
};