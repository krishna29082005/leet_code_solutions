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
            ans = 1;
           }else{
            ans = ci + 1;
           }
        }else{
            int pi = st.top().second;
            ans = ci - pi;

        }
        st.push({price , ci});
        ci++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */