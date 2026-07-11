class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int n = st1.size();
        if(st1.empty()) return -1;
        for(int i = 0 ; i < n - 1 ; i++){
            st2.push(st1.top());
            st1.pop();
        }
        int val = st1.top();
        st1.pop();
        int m = st2.size();
        for(int i = 0 ; i < m ; i++){
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        int n = st1.size();
        if(st1.empty()) return -1;
        for(int i = 0 ; i < n - 1 ; i++){
            st2.push(st1.top());
            st1.pop();
        }
        int val = st1.top();
        st1.pop();
        st2.push(val);
        int m = st2.size();
        for(int i = 0 ; i < m ; i++){
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    bool empty() {
        return st1.empty();
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