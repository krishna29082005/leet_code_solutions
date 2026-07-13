class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse(n); 
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
           
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
                st.push(i);
            }else{
                pse[i] = st.top();
                st.push(i);
            }
        }
        stack<int>st1;
        vector<int>nse(n);
        
        for(int i = n - 1; i >= 0 ; i--){
            
            while(!st1.empty() && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                nse[i] = n;
                st1.push(i);
            }else{
                nse[i] = st1.top();
                st1.push(i);
            }
        }
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int wid = nse[i] - pse[i] - 1;
            int area = heights[i]*wid;
            maxi = max(maxi , area);
        }
        return maxi;
    }
};