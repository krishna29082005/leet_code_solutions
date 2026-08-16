class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int>mp;
        vector<int>ans;

        int n = nums.size();
        int sum = 0;

        for(int i = 0 ; i < n ; i++){
        
            int presum = target - nums[i];
            if(mp.find(presum) != mp.end()){
                ans.push_back(mp[presum]);
                ans.push_back(i);
                return ans;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};