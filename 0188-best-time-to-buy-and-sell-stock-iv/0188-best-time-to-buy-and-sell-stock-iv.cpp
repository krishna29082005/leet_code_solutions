class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // dp[day][buy][cnt]
        vector<vector<int>>dp(2, vector<int>(k + 1, 0));
        // Base Cases:
        // dp[n][buy][cnt] = 0  (already initialized)
        // dp[day][buy][2] = 0  (already initialized)

        for (int day = n - 1; day >= 0; day--) {
            vector<vector<int>>temp(2, vector<int>(k + 1, 0));
            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = k - 1; cnt >= 0; cnt--) {

                    if (buy) {
                        int take =
                            -prices[day] + dp[0][cnt];

                        int notTake =
                            dp[1][cnt];

                        temp[buy][cnt] =
                            max(take, notTake);
                    }
                    else {
                        int sell =
                            prices[day] + dp[1][cnt + 1];

                        int notSell =
                            dp[0][cnt];

                        temp[buy][cnt] =
                            max(sell, notSell);
                    }
                }
            }
            dp = temp;
        }

        return dp[1][0];
    }
};