class StockSpanner {
public:
    stack<pair<int , int>>st;
    int ci = 0;
    StockSpanner() {
        
    }

    int next(int price) {
        int ans;
        while(!st.empty() && price >= st.top().first){
          st.pop();
        }
        if(st.empty()){
           if(ci == 0){

            st.push({price , ci});
            ans = 1;
            ci++;
            

           }else{
            
            st.push({price , ci});
            ans = ci + 1;
            ci++;
            
           }
        }else{
            int pi = st.top().second;
            st.push({price , ci});
            ans = ci - pi;
            ci++;

        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */