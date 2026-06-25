class Solution {
private:
        int money(int n , vector<int>& dp , vector<int>& nums){
            if(dp[n] != -1) return dp[n];
            int step2 = money(n - 2 , dp , nums);
            int step3 =  0;
            if(n - 3 >=0)
            step3 = money(n - 3 , dp , nums);
            
        
            return dp[n] = nums[n] + max(step2 , step3);
        }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        if(n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[1];
        int ans = max(money(n - 1 , dp , nums) , money(n - 2 , dp , nums));
        return ans;
        
    }
};

