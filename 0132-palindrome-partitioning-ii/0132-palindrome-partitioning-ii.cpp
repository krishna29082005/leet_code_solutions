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
    
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(s.size() + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            int mini = INT_MAX;
            for(int k = i ; k < n ; k++){
               if(check(i , k , s)){
                mini = min(mini , 1 + dp[k + 1]);
               }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};