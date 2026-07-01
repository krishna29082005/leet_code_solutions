class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }

        if(sum < abs(target)) return 0;
        sum = abs(sum - target);
        if(sum % 2 == 1) return 0;
        sum = sum/2;

        vector<int>dp(sum + 1 , -1);
        for(int i = 0 ; i < sum + 1 ; i++){// we know that we only need the last row 
        //to know the values.
            if(i == 0)
            dp[i] = 1;
            
            else 
            dp[i] = 0;
        }
       
        for(int i = nums.size() - 1 ; i >= 0 ; i--) {
            vector<int>temp(sum + 1 , 0);
            for(int j = 0 ; j < sum + 1 ; j++){
                
                int pick = 0;
                if(nums[i] <= j)//picking the current element
                    pick = dp[j - nums[i]];
                
                
                int nonpick = dp[j];
                            //not picking the current element
                temp[j] = pick + nonpick;
            }
            dp = temp;
        }
        return dp[sum];
    }
};