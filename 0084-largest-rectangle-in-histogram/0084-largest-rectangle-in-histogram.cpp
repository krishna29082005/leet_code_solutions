class Solution {
public:
     vector<int>nextsmall(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ns(n);
        for(int i = n - 1; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
               st.pop();
            }
            if(st.empty()){
                ns[i] = n;
                st.push(i);
            }
            else{
                ns[i] = st.top();
                st.push(i);
            }
        }
        return ns;
    }

    vector<int>prevsmall(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>ps(n);
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
               st.pop();
            }
            if(st.empty()){
                ps[i] = -1;
                st.push(i);
            }
            else{
                ps[i] = st.top();
                st.push(i);
            }
        }
        return ps;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ps = prevsmall(heights);
        vector<int>ns = nextsmall(heights);
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            int ls = ps[i];
            int rs = ns[i];
            int wid = rs - ls - 1;
            int area = heights[i]*wid;
            maxi = max(maxi , area);
        }
        return maxi;
    }
};