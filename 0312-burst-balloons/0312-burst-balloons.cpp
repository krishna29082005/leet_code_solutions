class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin() , 1);
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i > j) dp[i][j] = 0;
            }
        }

        for(int i = n - 1 ; i >= 1 ; i--){
            for(int j = i ; j < n - 1 ; j++){
                int maxi = 0;
                for(int k = i ; k <= j ; k++){
                   int left = dp[i][k - 1];
                   int right = dp[k + 1][j];
                   int merge = nums[i - 1]*nums[k]*nums[j + 1];
                   int sum = left + right + merge;
                   maxi = max(sum , maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};