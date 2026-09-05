class Solution {
    private:
    int f(int day , int buy , int cnt , vector<int>& prices , vector<vector<vector<int>>>& dp , int k){

        if(day == prices.size() || cnt == k) return 0;
        if(dp[day][buy][cnt] != -1) return dp[day][buy][cnt];

        if(buy){
            int wbuy = -prices[day] + f(day + 1 , 0 , cnt , prices , dp , k);

            int nbuy = 0 + f(day + 1 , 1 , cnt , prices , dp , k);

            return dp[day][buy][cnt] = max(wbuy , nbuy);
        }else{
            int wsell = prices[day] + f(day + 1 , 1 , cnt + 1 , prices , dp , k);

            int nsell = 0 + f(day + 1  , 0 , cnt , prices , dp , k);
            return dp[day][buy][cnt] = max(wsell , nsell);
        }
        return dp[day][buy][cnt] = 0;
    }
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(k + 1 , -1)));
        int ans = f(0 , 1 , 0 , prices , dp , k);
        return ans;
    }
};