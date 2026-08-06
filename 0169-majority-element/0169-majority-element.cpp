class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
       int cnt = 1;
       int num = nums[0];
       int n = nums.size();

       for(int i = 1 ; i < n ; i++){
           if(cnt == 0 && nums[i] != num){
               cnt = 1;
               num = nums[i];
           }
           else if(nums[i] == num) cnt++;
           else cnt--;
       }
       cnt = 0;
       for(int i = 0 ; i < n ; i++){
        if(nums[i] == num)cnt++;
       }
       if(cnt >= n/2) return num;
       return -1;
    }
};
