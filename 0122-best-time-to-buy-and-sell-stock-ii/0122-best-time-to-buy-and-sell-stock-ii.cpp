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
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        return f(0 , 1 , prices , dp);
    }
};