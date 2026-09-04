class Solution {
    private:
    bool f(int i , int j , int n , int m , string& s , string& p , vector<vector<int>>&dp){
        if(i == n && j == m) return true;
        if(i == n && j < m){
            for(int k = j ; k < m ; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(i < n && j == m) return false;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = f(i + 1 , j + 1 , n , m , s , p , dp);
        }
        else if(p[j] == '*'){
            int match = f(i + 1 , j , n , m , s , p , dp);
            int nomatch = f(i , j + 1 , n , m , s , p , dp);
            return dp[i][j] = match||nomatch;
        }
        else{
            return dp[i][j] = false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return f(0 , 0 , n , m , s , p , dp);
    }
};