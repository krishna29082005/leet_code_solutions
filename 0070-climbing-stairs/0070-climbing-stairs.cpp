class Solution {
private:
   
public:
    int climbStairs(int n) {
       vector<int> dp(n + 1 , -1);
       int prev1 = 1;
       int prev2 = 1;
       for(int i = 2 ; i <= n ; i++){
        int cur = prev1 + prev2;
        prev1 = prev2;
        prev2 = cur;
       }
       return prev2;
    }
};