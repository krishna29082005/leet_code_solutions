class Solution {
public:
    int f(int i , int j , string& s , string& p , vector<vector<int>>&dp){
        if(i < 0 && j < 0) return 1;
        if(i >=0 && j < 0) return 0;
        if(j >=0 && i < 0){
            for(int k = 0 ; k <= j ; k++){
                if(p[k] != '*') return 0;
            }
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j]){
            return dp[i][j] = f(i - 1 , j - 1 , s , p , dp);
           
        }
        if(p[j] == '?'){
            return dp[i][j] = f(i - 1 , j - 1 , s , p , dp);

        }

        if(p[j] == '*'){
        return dp[i][j] = f(i - 1 , j , s , p , dp)||f(i , j - 1 , s , p , dp);
 
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>>dp(m , vector<int>(n , -1));
        int ans = f(m - 1 , n - 1 , s , p , dp);
        if(ans == 1) return true;
        return false; 
    
    }
};