class MyQueue {
public:
    stack<int>st;
    
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
           int x = st.top();
           st.pop();

           if(st.empty()) return x;

           int ans = pop();

           st.push(x);
           return ans;
    }
    
    int peek() {
         int x = st.top();
           st.pop();

           if(st.empty())
           {
            st.push(x);
            return x;

           }
           int ans = peek();

           st.push(x);
           return ans;
    }
    
    bool empty() {
        if(st.empty()) return true;

        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */