class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[1] , nums[0]);
        for(int i = 2 ; i < n - 1 ; i++){
    
            int pick = nums[i] + prev2;
            int nonpick = 0 + prev1;
            int cur = max(pick , nonpick);
            prev2 = prev1;
            prev1 = cur;
        }
        int ans1 = prev1;
        
        if(n == 2) return max(nums[0] , nums[1]);
        int prev22 = nums[1];
        int prev21 = max(nums[1] , nums[2]);
        for(int i = 3 ; i < n ; i++){
    
            int pick = nums[i] + prev22;
            int nonpick = 0 + prev21;
            int cur2 = max(pick , nonpick);
            prev22 = prev21;
            prev21 = cur2;
        }
        int ans2 = prev21;
        return max(ans1 , ans2);
    }
};