class Solution {
public:
    int f(int i , int j , vector<int>&cuts , vector<vector<int>>&dp){

        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i ; k <= j ; k++){

            int left = f(i , k - 1, cuts , dp);
            int right = f(k + 1 , j , cuts , dp);
            int merge = cuts[j + 1] - cuts[i - 1]; 
            int cost = left + right + merge;
            mini = min(mini , cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);

        sort(cuts.begin() , cuts.end());

        vector<vector<int>>dp(cuts.size() , vector<int>(cuts.size() , -1));
        int ans = f(1 , cuts.size() - 2 , cuts , dp);
        return ans;
    }
};