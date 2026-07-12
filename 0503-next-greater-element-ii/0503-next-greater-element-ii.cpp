class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        temp = nums;
        temp.insert(temp.end() , nums.begin() , nums.end());
        stack<int>st;
        map<int ,int>mp;
        for(int i = 2*n - 1 ; i >= 0 ; i--){
            while(!st.empty() && temp[i] >= st.top()){
                st.pop();
            }

            if(st.empty()){
              mp[i] = -1;
              st.push(temp[i]);
            }else{
                mp[i] = st.top();
                st.push(temp[i]);
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};