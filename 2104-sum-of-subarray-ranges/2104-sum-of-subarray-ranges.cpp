class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i = 0 ; i < n ; i++){
            long long l = LLONG_MIN;
            long long s = LLONG_MAX;
            for(int j = i ; j < n ; j++){
                l = max(l, 1LL * nums[j]);
                s = min(s, 1LL * nums[j]);
                long long range = l - s;
                ans += range;
            }
        }
        return ans;
    }
};