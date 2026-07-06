class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size();
       vector<int>dp(n , 1);
       vector<int>parent(n);
       sort(nums.begin() , nums.end());

       for(int i = 0 ; i < n ; i++){
        parent[i] = i;
       }

       for(int i = 0 ; i < n ; i++){
           for(int j = 0 ; j < i ; j++){
           if(nums[i]%nums[j] == 0 && dp[j] + 1 > dp[i]){
              dp[i] = dp[j] + 1;
              parent[i] = j;
           }
         }
       }
       int li = 0;
       int maxi = 0;
       for(int i = 0 ; i < n ; i++){
        if(dp[i] > maxi){
            maxi =dp[i];
            li = i;
        }
       }
       vector<int>ans;
       while(parent[li] != li){
        ans.push_back(nums[li]);
        li = parent[li];
       }
       ans.push_back(nums[li]);
       return ans;
    }
};