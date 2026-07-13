class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
           
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }else{
            int flag = 1;
            while(!st.empty() && st.top() > 0){

                  if(st.top() == abs(asteroids[i])){
                    st.pop();
                    flag = 0;
                    break;
                    
                  }
                  else if(st.top() < abs(asteroids[i])){
                    st.pop();
                  }

                  else if(st.top() > abs(asteroids[i])){
                    flag = 0;
                    break;
                  }
                }
                if(flag == 1)
                st.push(asteroids[i]);
                
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