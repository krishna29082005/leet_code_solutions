class Solution {
public:
    int f(int i , int k ,vector<int>& arr , vector<int>&dp){
        int n = arr.size();
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int cmax = INT_MIN;
        int ans = INT_MIN;
        for(int j = i ; j < min(n,i + k) ; j++){
            
            cmax = max(arr[j] , cmax);
            int parsum = cmax*(j - i + 1);
            ans = max(ans , parsum +  f(j + 1 , k , arr , dp));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n , -1);
        int ans = f(0 , k , arr , dp);
        return ans;   
    }
};