class Solution {
private:
    int f(int i , int j , vector<vector<int>>& triangle 
        , int m , vector<vector<int>>& dp){
        if(i == 0 && j == 0)
        return triangle[0][0];
        

        int mini = 1e9;
        int a0 = 1e9;
        int a1 = 1e9;

        if(dp[i][j] != -1)return dp[i][j];

        if(j >= 0 && j < i)
        a0 = triangle[i][j] + f(i - 1 , j , triangle , m , dp);

        if(j - 1 >= 0 && j - 1 < i)
        a1 = triangle[i][j] + f(i - 1 , j - 1 , triangle , m , dp);


        mini = min(a0 , a1);
        
        return dp[i][j] = mini;
    }
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int mini = 1e9;
        int size = triangle[m-1].size();
        vector<vector<int>> dp(m , vector<int>(m , -1));
        for(int x = 0 ; x < size ; x++){
            int sum = f(m - 1 , x , triangle , m , dp);
            mini = min(mini , sum);
        } 
        return mini;
    }
};