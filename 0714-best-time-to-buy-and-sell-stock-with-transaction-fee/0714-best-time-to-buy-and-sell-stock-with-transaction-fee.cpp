class Solution {
    private:
    int f(int day , int buy , vector<int>& prices , vector<vector<int>>&dp
    , int fee){
        if(day == prices.size()) return 0;
        if(dp[day][buy] != -1)return dp[day][buy];
        if(buy){
            int wbuy = -prices[day] + f(day + 1 , 0 , prices , dp , fee);

            int nbuy = 0 + f(day + 1 , 1 , prices , dp , fee);
            return dp[day][buy] = max(wbuy , nbuy);
        }else{
            int wsell = prices[day] - fee + f(day + 1 , 1 , prices , dp , fee);

            int nsell = 0 + f(day + 1  , 0 , prices , dp , fee);
            return dp[day][buy] = max(wsell , nsell);
        }
        return dp[day][buy] = 0;
    }
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        int ans = f(0 , 1 , prices , dp , fee);
        return ans;
    }
    
};