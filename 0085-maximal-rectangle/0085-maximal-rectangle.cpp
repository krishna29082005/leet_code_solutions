class Solution {
public:
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
        
        for(int i = 0 ; i < n ; i++){
            int wid = nse[i] - pse[i] - 1;
            int area = heights[i]*wid;
            maxi = max(maxi , area);
        }
        
    }
    return maxi;
    }
};
