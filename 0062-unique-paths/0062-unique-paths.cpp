class Solution {
private: 
   
public:
    int uniquePaths(int m, int n) {
     vector<int>dp(n);
     
     for(int i = 0 ; i < m ; i++)
     {
        vector<int>temp(n);
        for(int j = 0 ; j < n ; j++){
            if(i == 0 && j == 0){
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;
            if(i - 1 >= 0){
                up = dp[j];
            }
            if(j - 1 >= 0){
                left = temp[j - 1];
            }
            temp[j] = up + left;
        }
        dp = temp;
     }
     return dp[n - 1];   
    }
};