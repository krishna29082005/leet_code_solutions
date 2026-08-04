class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        int flag = 0;
        for(int i = 0 ; i < n ; i++){
           
            sum = sum + nums[i];
            if(sum < 0) sum = 0;
            maxi = max(maxi , sum);
            if(nums[i] > 0) flag = 1;
        }
        int ans = INT_MIN;
        if(flag == 0){
            for(int i = 0 ; i < n ; i++){
                ans = max(ans , nums[i]);
            }
            return ans;
        }
        return maxi;
    }
};