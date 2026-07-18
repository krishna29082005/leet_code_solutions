class Solution {
public:

    int trap(vector<int>& height) {
       int n = height.size();
       stack<int>st;
       int water = 0;
       for(int i = 0 ; i < n ; i++){
        while(!st.empty() && height[i] > height[st.top()]){
            int bottom = st.top();
            st.pop();

            if(st.empty()) break;

            int leftw = st.top();

            int wid = i - leftw - 1;

            int lev = min(height[i] , height[leftw]) - height[bottom];

            water += lev*wid;
        }
        st.push(i);
       }
       return water;
    }
};