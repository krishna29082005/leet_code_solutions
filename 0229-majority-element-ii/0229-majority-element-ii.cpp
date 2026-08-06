class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int cnt1 = 0;
        int e1 = 0;
        int cnt2 = 0;
        int e2 = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(cnt1 == 0 && nums[i] != e2){
                cnt1 = 1;
                e1 = nums[i];
            }
            else if(cnt2 == 0 && e1 != nums[i]){
                cnt2 = 1;
                e2 = nums[i];
            }
            else if(e1 == nums[i]){
                cnt1++;
            }
            else if(e2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1-- , cnt2--;
            }
        }
            cnt1 = 0;
            cnt2 = 0;
            for(int i = 0 ; i < n ; i++){
                if(e1 == nums[i]) cnt1++;
                if(e2 == nums[i]) cnt2++;
            }
            vector<int> ans;
            if(cnt1 > n/3){
                ans.push_back(e1);
            }
            if(cnt2 > n/3){

                if(e2 != e1)
                ans.push_back(e2);
                
            }
        return ans;
    }
};