class Solution {
    private:
    int f(int day , int cb , vector<int>&prices , vector<vector<int>>&dp){
         if(day == prices.size()) return 0;

         if(dp[day][cb] != -1) return dp[day][cb];

         if(cb == 1){
            int buy = -prices[day] + f(day + 1 , 0 , prices , dp);
            int nbuy = 0 + f(day + 1 , 1 , prices , dp);
            return dp[day][cb] = max(buy , nbuy); 
         }
         else{
            int sell = prices[day] + f(day + 1 , 1 , prices , dp);
            int nsell = 0 + f(day + 1 , 0 , prices , dp);
            return dp[day][cb] = max(sell , nsell);
         }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(2 , -1);
        for(int i = 0 ; i < 2 ; i++){
           dp[i] = 0;
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            vector<int>temp(2);
            for(int j = 0 ; j < 2 ; j++){
                if(j == 1){
                     int buy = -prices[i] + dp[0];
                     int nbuy = 0 + dp[1];
                     temp[j] = max(buy , nbuy);
                }
                else{
                     int sell = prices[i] + dp[1];
                     int nsell = 0 + dp[0];
                     temp[j] = max(sell , nsell);
                }
            }
            dp = temp;
        }
        return dp[1];
    }
};