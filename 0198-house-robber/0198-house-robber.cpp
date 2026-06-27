class Solution {
private:
    int f(int n , vector<int>& dp , vector<int>& nums){
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        int pick = nums[n] + f(n - 2 , dp , nums);
        int nonpick = 0 + f(n - 1 , dp , nums);
        return dp[n] = max(pick , nonpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);
        for(int i = 2 ; i < n ; i++){
            int pick = nums[i] + dp[i - 2];
            int nonpick = 0 +  dp[i - 1];

            dp[i] = max(pick , nonpick);
        }
        return dp[n - 1];
    }
};

