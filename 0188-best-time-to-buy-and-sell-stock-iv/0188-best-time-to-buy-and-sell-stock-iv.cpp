class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // dp[day][buy][cnt]
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );

        // Base Cases:
        // dp[n][buy][cnt] = 0  (already initialized)
        // dp[day][buy][2] = 0  (already initialized)

        for (int day = n - 1; day >= 0; day--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = k - 1; cnt >= 0; cnt--) {

                    if (buy) {
                        int take =
                            -prices[day] + dp[day + 1][0][cnt];

                        int notTake =
                            dp[day + 1][1][cnt];

                        dp[day][buy][cnt] =
                            max(take, notTake);
                    }
                    else {
                        int sell =
                            prices[day] + dp[day + 1][1][cnt + 1];

                        int notSell =
                            dp[day + 1][0][cnt];

                        dp[day][buy][cnt] =
                            max(sell, notSell);
                    }
                }
            }
        }

        return dp[0][1][0];
    }
};