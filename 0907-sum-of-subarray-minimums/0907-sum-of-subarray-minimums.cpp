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
    int sumSubarrayMins(vector<int>& arr) {
    int mod = 1e9 + 7;
    vector<int> ns = nextsmall(arr);
    vector<int> ps = prevsmall(arr);
    int ans = 0;
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        long long lc = i - ps[i];
        long long rc = ns[i] - i;
        long long total = (lc*rc*arr[i])%mod;
        ans  = (ans + total)%mod;
    }
    return ans;
    }
};