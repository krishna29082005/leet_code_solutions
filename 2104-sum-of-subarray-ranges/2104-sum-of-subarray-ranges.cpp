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

    vector<int>nextbig(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>nb(n);
        for(int i = n - 1; i >= 0 ; i--){
            while(!st.empty() && arr[i] >= arr[st.top()]){
               st.pop();
            }
            if(st.empty()){
                nb[i] = n;
                st.push(i);
            }
            else{
                nb[i] = st.top();
                st.push(i);
            }
        }
        return nb;
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

    vector<int>prevbig(vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        vector<int>pb(n);
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
               st.pop();
            }
            if(st.empty()){
                pb[i] = -1;
                st.push(i);
            }
            else{
                pb[i] = st.top();
                st.push(i);
            }
        }
        return pb;
    }

    long long subArrayRanges(vector<int>& nums) {
     int n = nums.size();
     vector<int>ps;  
     vector<int>pb; 
     vector<int>ns; 
     vector<int>nb; 

     ps = prevsmall(nums);
     pb = prevbig(nums);
     ns = nextsmall(nums);
     nb = nextbig(nums);
     long long temp1 = 0;
     long long temp2 = 0;
     for(int i = 0 ; i < n ; i++){
        long long lc = i - ps[i];
        long long rc = ns[i] - i;
        temp1 += 1LL*lc*rc*nums[i];

        long long lc1 = i - pb[i];
        long long rc1 = nb[i] - i;
        temp2 += 1LL*lc1*rc1*nums[i];
     } 
     return temp2 - temp1;
    }
};