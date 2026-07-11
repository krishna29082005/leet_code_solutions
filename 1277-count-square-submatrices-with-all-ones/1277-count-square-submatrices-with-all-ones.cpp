class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n , vector<int>(m , 0));
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1){
                    int left = 0;
                    int up = 0;
                    int dia = 0;

                    if(i - 1 >= 0) up = dp[i - 1][j];
                    if(j - 1 >= 0) left = dp[i][j - 1];
                    if(i - 1 >= 0 && j - 1 >= 0) dia = dp[i - 1][j - 1];

                    dp[i][j] = 1 + min(up , min(left , dia));
                    ans += dp[i][j];
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};