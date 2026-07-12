class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        stack<int>st;
        map<int ,int>mp;

        for(int i = 2*n - 1 ; i >= 0 ; i--){
            while(!st.empty() &&  nums[i % n] >= st.top()){
                st.pop();
            }

            if(st.empty()){
              mp[i] = -1;
              st.push(nums[i % n]);
            }else{
                mp[i] = st.top();
                st.push(nums[i % n]);
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};