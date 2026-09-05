class Solution {
    private:
    int f(int day , int cb , int cnt , vector<int>&prices , vector<vector<vector<int>>>&dp){
         if(day == prices.size()) return 0;
         if(cnt == 2) return 0;

         if(dp[day][cb][cnt] != -1) return dp[day][cb][cnt];

         if(cb == 1){
            int buy = -prices[day] + f(day + 1 , 0 , cnt , prices , dp);
            int nbuy = 0 + f(day + 1 , 1 , cnt , prices , dp);
            return dp[day][cb][cnt] = max(buy , nbuy); 
         }
         else{
            int sell = prices[day] + f(day + 1 , 1 , cnt + 1 , prices , dp);
            int nsell = 0 + f(day + 1 , 0 , cnt , prices , dp);
            return dp[day][cb][cnt] = max(sell , nsell);
         }
    }
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , 
                                      vector<int>(3 , -1)));
        return f(0 , 1 , 0 , prices , dp);


        // for(int j = 0 ; j < 2 ; j++){
        //         dp[j][2] = 0;
        //     }
    
        // for(int i = n - 1 ; i >= 0  ; i--){
        //     vector<vector<int>>temp(2 , vector<int>(3 , 0));
        //     for(int j = 0 ; j < 2 ; j++){
        //         for(int k = 1 ; k >= 0 ; k--){
        //             if(j == 1){
        //                 int buy = -prices[i] + dp[0][k];

        //                 int nbuy = 0 + dp[1][k];
        //                 temp[j][k] = max(buy , nbuy);
        //             }
        //             else{
        //                 int sell = prices[i] +  dp[1][k+1];
                        
        //                 int nsell = 0 + dp[0][k];
        //                 temp[j][k] = max(sell , nsell);
        //             }
        //         }
        //     }
        //     dp = temp;
        // }
        // return dp[1][0];
    }
};