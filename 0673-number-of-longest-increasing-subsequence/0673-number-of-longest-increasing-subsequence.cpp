class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>count(n , 1);
        vector<int>dp(n , 1);

        for(int i = 1 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }
                    else if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        int cnt = 0;
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                cnt = count[i];
            }
            else if(dp[i] == maxi)
            cnt += count[i];
        } 
        return cnt;
    }
};