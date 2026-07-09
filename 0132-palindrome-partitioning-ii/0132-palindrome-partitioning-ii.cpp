class Solution {
public:
    bool check(int i , int j , string& s){
        if(i == j) return true;
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i , string &s , vector<int>&dp){
        if(i == s.size()) return 0;
         
        if(dp[i] != -1) return dp[i]; 
        int mini = INT_MAX;
        for(int k = i ; k < s.size() ; k++)
        {
            if(check(i , k , s)){
                mini = min(mini , 1 + f(k + 1 , s , dp));
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        vector<int>dp(s.size() , -1);
        int ans = f(0 , s , dp);
        return ans - 1;
    }
};