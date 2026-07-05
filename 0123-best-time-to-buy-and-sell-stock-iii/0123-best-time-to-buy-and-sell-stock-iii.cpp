class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2 , vector<int>(3 , -1)));
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 3 ; j++)
            dp[n][i][j] = 0;
        }
        for(int i = 0 ; i < n + 1 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                dp[i][j][2] = 0;
            }
        }

        for(int i = n - 1 ; i >= 0  ; i--){
            for(int j = 0 ; j < 2 ; j++){
                for(int k = 1 ; k >= 0 ; k--){
                    if(j == 1){
                        int buy = -prices[i] + dp[i + 1][0][k];

                        int nbuy = 0 + dp[i + 1][1][k];
                        dp[i][j][k] = max(buy , nbuy);
                    }
                    else{
                        int sell = prices[i] +  dp[i + 1][1][k+1];
                        
                        int nsell = 0 + dp[i + 1][0][k];
                        dp[i][j][k] = max(sell , nsell);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};