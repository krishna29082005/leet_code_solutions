class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        map<int , int>mp;
        stack<int>st;

        for(int i = n2 - 1 ; i >= 0 ; i--){

            while(!st.empty() && nums2[i] >= st.top()){
               st.pop();
            }

            if(st.empty()) 
            {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }else{
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        } 
        vector<int>ans;
        for(int i = 0 ; i < n1 ; i++){
            if(mp.find(nums1[i]) != mp.end()){
                ans.push_back(mp[nums1[i]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};