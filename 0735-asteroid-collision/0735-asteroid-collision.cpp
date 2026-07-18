class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int>ans;
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else
            {
                int flag = 1;

                while(!st.empty() && st.top() > 0){
                    
                    if(abs(asteroids[i]) == st.top()){
                        flag = 0;
                        st.pop();
                        break;
                        
                    }
                    else if(abs(asteroids[i]) < st.top()){
                        flag = 0;
                        break;
                        
                    }
                    else if(abs(asteroids[i]) > st.top()){
                        st.pop();
                    }
                }
                if(flag == 1){
                    st.push(asteroids[i]);
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};