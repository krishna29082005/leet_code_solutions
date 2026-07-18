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
            while(!st.empty() && arr[st.top()] > arr[i]){
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


    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = INT_MIN;
        vector<int>heights(n , 0);
        for(int i = 0 ; i < m ; i++){
           
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == '0') heights[j] = 0;
                else heights[j] += 1;
            }
        
        
        vector<int>ps = prevsmall(heights);
        vector<int>ns = nextsmall(heights);
        for(int j = 0 ; j < n ; j++){
        int ls = ps[j];
        int rs = ns[j];
        int wid = rs - ls - 1;
        int area = heights[j]*wid;
        maxi = max(maxi , area);
        }
    }
    return maxi;
    }
};
