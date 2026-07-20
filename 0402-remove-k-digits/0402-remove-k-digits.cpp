class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        string ans;
        if(num.size() == 1 && k == 1) return "0";
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top() > num[i]){
                if(k == 0) break;
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k != 0)
        {
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        while(ans.size() > 0 && ans[0] == '0'){
            ans.erase(0 , 1);
        }
        if(ans.empty()) return "0";
        return ans;
   }
};