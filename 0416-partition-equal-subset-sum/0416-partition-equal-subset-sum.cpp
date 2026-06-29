class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        for(int i = 0 ; i < n ; i++){
            sum1 += nums[i];
        }
        if(sum1 % 2 != 0) return false;
        int sum = sum1/2;
        vector<int>dp(sum + 1 , -1);
        
        
        
        for(int i = 0 ; i < sum + 1 ; i++){// we know that we only need the last row 
        //to know the values.
            if(i == 0)
            dp[i] = 1;
            
            else 
            dp[i] = 0;
        }
       
        for(int i = n - 1 ; i >= 0 ; i--) {
            vector<int>temp(sum + 1 , -1);
            for(int j = 0 ; j < sum + 1 ; j++){
                
                int pick = 0;
                if(nums[i] <= j)//picking the current element
                    pick = dp[j - nums[i]];
                
                
                    int nonpick = dp[j];
                            //not picking the current element
                if(pick == 1 || nonpick == 1) temp[j] = 1;
                else temp[j] = 0;
            }
            dp = temp;
        }
        if(dp[sum] == 1) return true;
        return  false;
    }
};