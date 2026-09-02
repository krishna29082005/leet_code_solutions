class Solution {
private:
    
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
       if(n == 0) return 0;
       if(n == 1) return nums[0];
       
       int prev2 = nums[0];
       int prev1 = max(nums[0] , nums[1]);
       for(int i = 2 ; i < n ; i++){
         int pick = nums[i] + prev2;
         int nonpick = prev1;

         int cur = max(pick , nonpick);
         prev2 = prev1;
         prev1 = cur;

       } 
       return prev1;
    }
};

