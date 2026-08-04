class Solution {
private:
int ans = INT_MIN;
public:
    void helper(vector<int>& nums , int pmax , int pmin , int i){
        if(i == nums.size()) return;
        int cmax = max(nums[i] , max(pmax*nums[i] , pmin*nums[i]));
        int cmin = min(nums[i] , min(pmax*nums[i] , pmin*nums[i]));
        helper(nums , cmax , cmin , i + 1);
        ans = max(ans , cmax);
        return;
    }
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      helper(nums , 1 , 1 , 0);
      return ans;
    }
};