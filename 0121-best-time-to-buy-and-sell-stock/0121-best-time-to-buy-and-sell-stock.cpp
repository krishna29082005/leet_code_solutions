class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int mini = prices[0];
      int profit = INT_MIN;
      int n = prices.size();
      for(int i = 1 ; i < n ; i++){
          int temp = prices[i] - mini;
          mini = min(prices[i] , mini);
          profit = max(profit , temp);
      }
      if(profit == -1 || n == 1) return 0;
      return profit;
    }
};