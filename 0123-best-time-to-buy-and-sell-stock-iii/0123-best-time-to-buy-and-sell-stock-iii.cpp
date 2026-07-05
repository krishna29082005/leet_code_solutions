class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(2 , vector<int>(3 , 0));
        
        for(int j = 0 ; j < 2 ; j++){
                dp[j][2] = 0;
            }
    
        for(int i = n - 1 ; i >= 0  ; i--){
            vector<vector<int>>temp(2 , vector<int>(3 , 0));
            for(int j = 0 ; j < 2 ; j++){
                for(int k = 1 ; k >= 0 ; k--){
                    if(j == 1){
                        int buy = -prices[i] + dp[0][k];

                        int nbuy = 0 + dp[1][k];
                        temp[j][k] = max(buy , nbuy);
                    }
                    else{
                        int sell = prices[i] +  dp[1][k+1];
                        
                        int nsell = 0 + dp[0][k];
                        temp[j][k] = max(sell , nsell);
                    }
                }
            }
            dp = temp;
        }
        return dp[1][0];
    }
};