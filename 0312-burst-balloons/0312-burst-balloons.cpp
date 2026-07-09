class Solution {
public:
    int f(int i , int j , vector<int>& nums , vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        for(int k = i ; k <= j ; k++){
            int left = f(i , k - 1 , nums , dp);
            int right = f(k + 1 , j , nums , dp);
            int merge = nums[i - 1]*nums[k]*nums[j + 1];
            int sum = left + right + merge;
            maxi = max(sum , maxi);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        int ans = f(1 , n - 2 , nums , dp);
        return ans;
    }
};