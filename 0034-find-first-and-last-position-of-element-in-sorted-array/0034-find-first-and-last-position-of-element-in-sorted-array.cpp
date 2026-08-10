class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans1 = -1;
        vector<int> temp;
        if(nums.size() == 0) return {- 1, - 1};
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] <= target){
                ans1 = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        int ans2 = -1;
        l = 0;
        r = n - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] >= target){
                ans2 = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(ans2 != -1 && nums[ans2] == target)temp.push_back(ans2);
        else temp.push_back(-1);
        if(ans1 != -1 && nums[ans1] == target)temp.push_back(ans1);
        else temp.push_back(-1);
        return temp;
    }
};