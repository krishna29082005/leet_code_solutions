class Solution {
public:
    void f(int i , int j , string& s1 , string& s2 , string & cur,vector<vector<int>>&dp){
        //base case

          if(i == 0){//add remaining from s2;
            while(j > 0){
                cur += s2[j - 1];
                j--;
                }
                return;
          }

          if(j == 0){//add remaining from s1;
            while(i > 0){
                cur += s1[i - 1];
                i--;
            }
            return;
          }
        //base case end

          if(s1[i - 1] == s2[j - 1]){// add common element only once;
            cur += s1[i - 1];
            return f(i - 1 , j - 1 , s1 , s2 , cur , dp);
          }
          else{
          int up = dp[i - 1][j];
          int left = dp[i][j - 1];

          if(up >= left){//add from the string which gives use longer
            cur += s1[i - 1];
            return f(i - 1 , j , s1 , s2 , cur , dp);
          }
          else{//add from the string which gives us longer
            cur += s2[j - 1];
           return f(i , j - 1 , s1 , s2 , cur , dp);
          }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>>dp(m + 1 , vector<int>(n + 1 , 0));
        
        for(int i = 0 ; i < n + 1 ; i++){
            dp[0][i] = 0;
        }
        for(int i = 0 ; i < m + 1 ; i++){
            dp[i][0] = 0;
        }

        for(int i = 1 ; i < m + 1 ; i++){
            for(int j = 1 ; j < n + 1 ; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    int up = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    dp[i][j] = max(up , left);
                }
            }
        }
        string cur = "";
        f(m , n , str1 , str2 , cur , dp);
        reverse(cur.begin() , cur.end());
        return cur;
    }
};