class Solution {
public:
    vector<int> presmall(vector<int>& arr){
        stack<int>st;
        int n = arr.size();
        vector<int>ps(n);
        for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
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

    vector<int> nextsmall(vector<int>& arr){
        stack<int>st;
        int n = arr.size();
        vector<int>ns(n);
        for(int i = n - 1 ; i >= 0 ; i--){
        while(!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }

        if(st.empty()){
            ns[i] = arr.size();
            st.push(i);
        }
        else{
            ns[i] = st.top();
            st.push(i);
        }
    }
    return ns;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int>ns;
        vector<int>ps;
        ns = nextsmall(arr);
        ps = presmall(arr);

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            long long  lc = i - ps[i];
            long long rc = ns[i] - i;
            long long temp = (arr[i]*lc*rc)%mod;
            ans = (ans + temp)%mod;
            
        }
        return ans%mod;
    }
};