class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);

        sort(cuts.begin() , cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(cuts.size() , vector<int>(cuts.size() , -1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i > j)dp[i][j] =0;
            }
        }

        
        
        for(int i = m - 2 ; i >= 1 ; i--){
            for(int j = i ; j < m - 1 ; j++){
                int mini = INT_MAX;
                for(int k = i ; k <= j ; k++){
                    
                    int left = dp[i][k - 1];
                    int right = dp[k + 1][j];
                    
                    int cost = cuts[j + 1] - cuts[i - 1];
                    int sum = left + right + cost;
                    mini = min(sum , mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m - 2];
    }
};