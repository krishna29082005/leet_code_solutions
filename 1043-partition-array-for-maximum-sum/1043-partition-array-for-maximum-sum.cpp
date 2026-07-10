class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n + 1 , 0);
        for(int i = n - 1 ; i >= 0 ; i--){
            int cmax = INT_MIN;
            int ans = INT_MIN;
            for(int j = i ; j < min(n , i + k) ; j++){
                cmax = max(arr[j] , cmax);
                int parsum = cmax*(j - i + 1);
                ans = max(ans , parsum +  dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0]; 
    }
};