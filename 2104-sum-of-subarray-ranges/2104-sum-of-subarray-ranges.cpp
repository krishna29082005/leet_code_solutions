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
    vector<int> prebig(vector<int>& arr){
        stack<int>st;
        int n = arr.size();
        vector<int>pb(n);
        for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
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

    vector<int> nextbig(vector<int>& arr){
        stack<int>st;
        int n = arr.size();
        vector<int>nb(n);
        for(int i = n - 1 ; i >= 0 ; i--){
        while(!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }

        if(st.empty()){
            nb[i] = arr.size();
            st.push(i);
        }
        else{
            nb[i] = st.top();
            st.push(i);
        }
    }
    return nb;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>ns;
        vector<int>ps;
        vector<int>nb;
        vector<int>pb;
        ns = nextsmall(nums);
        ps = presmall(nums);
        nb = nextbig(nums);
        pb = prebig(nums);

        long long temp1 = 0;
        long long temp2 = 0;
        for(int i = 0 ; i < n ; i++){
            long long lc = i - ps[i];
            long long rc = ns[i] - i;
            temp1 += nums[i]*lc*rc;
            
            long long lb = i - pb[i];
            long long rb = nb[i] - i;
            temp2 += nums[i]*lb*rb;   
        }
        return temp2 - temp1;
    }
};