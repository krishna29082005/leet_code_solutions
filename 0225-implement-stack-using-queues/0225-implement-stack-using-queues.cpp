class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
       
    }
    
    void push(int x) {
       q1.push(x);
       int n = q1.size();
       for(int i = 0 ; i < n - 1 ; i++){
          int temp = q1.front();
          q1.pop();
          q1.push(temp);
       }
    }
    
    int pop() {
        if(q1.empty()) return -1;
       int temp = q1.front();
       q1.pop();
       return temp;
       }
    
    
    int top() {
       if(q1.empty()) return -1;
       int temp = q1.front();
       
       return temp;
       }
    
    
    bool empty() {
       if(q1.empty()) return true;

       return false; 
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */