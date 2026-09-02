class Solution {
private:
    int helper(int n , vector<int>& nums , vector<int>&dp){
        if(n == 0) return dp[n] = nums[n];
        if(n == 1) return dp[n] = max(nums[n] , nums[n - 1]);

        if(dp[n] != -1) return dp[n];

        int pick = nums[n] + helper(n - 2 , nums , dp);
        int nonpick = helper(n - 1 , nums , dp);

        return dp[n] = max(pick , nonpick);
    }
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n , -1);
       return helper(n - 1 , nums , dp);
    }
};

