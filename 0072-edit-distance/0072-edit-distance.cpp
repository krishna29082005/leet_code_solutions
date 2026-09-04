class Solution {
private:
int f(int i , int j , int n , int m , string& word1 , string& word2 , vector<vector<int>>&dp){
   
    if(i == n && j == m) return 0;
    if(i == n && j < m) return m - j;
    if(i < n && j == m) return n - i;
   
    if(dp[i][j] != -1) return dp[i][j];

    if(word1[i] == word2[j]){
        return f(i + 1 , j + 1 , n , m , word1 , word2 , dp);
    }
    int del = 1 + f(i + 1 , j , n , m , word1 , word2 , dp);
    int ins = 1 + f(i , j + 1 , n , m , word1 , word2 , dp);
    int rep = 1 + f(i + 1 , j + 1 , n , m , word1 , word2 , dp);

    return dp[i][j] = min(del , min(ins , rep));
}
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return f(0 , 0 , n , m , word1 , word2 , dp);
    }
};