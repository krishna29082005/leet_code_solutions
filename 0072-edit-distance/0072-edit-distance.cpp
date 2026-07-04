class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m + 1 , 
                              vector<int>(n + 1 , 0));
        dp[0][0] = 0;
        for(int j = 1 ; j < n + 1 ; j++){
            dp[0][j] = j;//because its no more 0 based we made it 1 based
        }
        for(int i = 1 ; i < m + 1 ; i++){
            dp[i][0] = i;//same
        }
        
        for(int i = 1 ; i < m + 1 ; i++){
           for(int j = 1 ; j < n + 1 ; j++){
            if(word1[i - 1] == word2[ j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }
            int del = 1 + dp[i - 1][j];
            int rep = 1 + dp[i - 1][j - 1];
            int ins = 1 + dp[i][j - 1];
            dp[i][j] = min(del , min(rep , ins));
           }
        }
        return dp[m][n];
    }
};