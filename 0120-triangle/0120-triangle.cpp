class Solution {
private:
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        vector<int> dp(m);
        dp[0] = triangle[0][0];

        for(int i = 0 ; i < m ; i++){
            vector<int> temp(m);
            if(i == 0) 
            {
                temp[i] = 0;
                continue;
            }
            
            int sizein = triangle[i].size();
            for(int j = 0 ; j < sizein ; j++){
                
                int mini = 1e9;
                int a0 = 1e9;
                int a1 = 1e9;

                if(j >= 0 && j < i)
                a0 = triangle[i][j] + dp[j];

                if(j - 1 >= 0 && j - 1 < i)
                a1 = triangle[i][j] + dp[j - 1];

                mini = min(a0 , a1);

                temp[j] = mini;
            }
            dp = temp;
        }
        int mini = INT_MAX;
        for(int j = 0; j < m ; j++)
        {
        mini = min(mini, dp[j]);
        }
        return mini;
    }
};