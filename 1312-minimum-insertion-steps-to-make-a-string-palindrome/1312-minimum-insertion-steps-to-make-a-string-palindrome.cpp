class Solution {
public:
    int f(int i , int j , string& s1 , string & s2 , vector<vector<int>>&dp){

        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        if(s1[i] == s2[j]) return dp[i][j] = 1 + f(i - 1 , j - 1 , s1 , s2 , dp);
        
        int a = f(i - 1 , j , s1 , s2 , dp);
        int b = f(i , j - 1 , s1 , s2 , dp);
        return dp[i][j] = max(a , b);
    }

    int minInsertions(string s){
        string s1 = s;
        string s2 = s;
        reverse(s2.begin() , s2.end());
        vector<vector<int>>dp(s.size() , vector<int>(s2.size() , -1));
        int ans = f(s1.size() - 1 , s2.size() - 1  , s1 , s2 , dp);
        return s.size() - ans;
    }
};