class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        string ans;
        if(num.size() == 1 && k == 1) return "0";
        for(int i = 0 ; i < n ; i++){
        while(!st.empty() && st.top() > num[i] && k > 0){

            st.pop();
            k--;
        }
        st.push(num[i]);
        }
        while(k > 0){
        st.pop();
        k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        int i = 0;
        while(true){
            if(ans[i] != '0') break;
            else ans.erase(i , 1);
        }
        if(ans.empty()){
            return "0";
        }
        return ans; 
   }
};