class Solution {
public:
    int f(int day , int buy , vector<int>& prices , vector<vector<int>>&dp){
        if(day >= prices.size()) return 0;
        if(dp[day][buy] != -1)return dp[day][buy];

        if(buy){
            int wbuy = -prices[day] + f(day + 1 , 0 , prices , dp);

            int nbuy = 0 + f(day + 1 , 1 , prices , dp);
            return dp[day][buy] = max(wbuy , nbuy);
        }else{
            int wsell = prices[day] + f(day + 2 , 1 , prices , dp);

            int nsell = 0 + f(day + 1  , 0 , prices , dp);
            return dp[day][buy] = max(wsell , nsell);
        }
        return dp[day][buy] = 0;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        int ans = f(0 , 1 , prices , dp);
        return ans;
    }
};