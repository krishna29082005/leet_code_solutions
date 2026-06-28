class Solution {
private:
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        vector<vector<int>> dp(m , vector<int>(m , -1));
        dp[0][0] = triangle[0][0];

        for(int i = 0 ; i < m ; i++){
            if(i == 0) continue;
            int sizein = triangle[i].size();
            for(int j = 0 ; j < sizein ; j++){
                
                int mini = 1e9;
                int a0 = 1e9;
                int a1 = 1e9;

                if(j >= 0 && j < i)
                a0 = triangle[i][j] + dp[i - 1][j];

                if(j - 1 >= 0 && j - 1 < i)
                a1 = triangle[i][j] + dp[i - 1][j - 1];

                mini = min(a0 , a1);

                dp[i][j] = mini;
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < triangle[m - 1].size() ; j++)
        mini = min(mini, dp[m - 1][j]);

        return mini;
    }
};