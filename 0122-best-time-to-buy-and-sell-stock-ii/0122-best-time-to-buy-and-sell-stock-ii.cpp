class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(2 , 0);
        
        for(int i = n - 1 ; i >= 0  ; i--){
            vector<int>temp(2 , 0);
            for(int j = 0 ; j < 2 ; j++){
                if(j == 1){
                    int buy = -prices[i] + dp[0];
                    int nbuy = dp[1];
                    temp[j] = max(buy , nbuy);
                }
                else{
                    int sell = prices[i] +  dp[1];
                    int nsell = 0 + dp[0];
                    temp[j] = max(sell , nsell);
                }
            }
            dp = temp;
        }
        return dp[1];
    }
};