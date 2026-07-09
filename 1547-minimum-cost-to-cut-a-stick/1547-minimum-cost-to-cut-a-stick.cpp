class Solution {
public:
    int f(int i , int j , vector<int>& cuts , vector<vector<int>>&dp){
        if(i > j) return 0;
        
        int mini = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k <= j ; k++){

            int left = f(i , k - 1 , cuts , dp);
            int right = f(k + 1 , j , cuts , dp);
            int merge = cuts[j + 1] - cuts[i - 1];
            int sum = left + right + merge;
            mini = min(mini , sum);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
  
        int m = cuts.size();
        vector<vector<int>>dp(m , vector<int>(m , -1));
        sort(cuts.begin() , cuts.end());
        int ans = f(1 , m - 2 , cuts , dp);
        return ans;
    } 
};