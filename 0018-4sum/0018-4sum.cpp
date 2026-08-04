class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1 ; j < n ; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int k = n - 1;
                while(l < k)
                { 
                    
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[k];
                    if(sum < target) l++;
                    else if(sum > target) k--;
                    else
                    {
                    ans.push_back({nums[i] ,nums[j] ,nums[l] ,nums[k]});
                    l++;
                    k--;
                    while(l < k && nums[l] == nums[l - 1]) l++;
                    while(l < k && nums[k] == nums[k + 1]) k--;

                    }
                }
            }
        }
        return ans;
    }
};
