class Solution {
private:
        int money(int n , vector<int>&dp , vector<int>& nums){
            if(n == 0) return nums[0];
            if(n < 0) return 0;
            if(dp[n] != -1) return dp[n];
            int pick = nums[n] + money(n - 2 , dp , nums);
            int nonpick = 0 + money(n - 1 , dp , nums);
            return dp[n] = max(pick , nonpick);
        }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        if(n == 1) return nums[0];
        int ans = money(n - 1 , dp , nums);
        return ans;
        
    }
};

