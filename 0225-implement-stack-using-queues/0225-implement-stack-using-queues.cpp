class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
       
    }
    
    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
       if(q1.empty()) return -1;
       else{
        int n = q1.size();
        for(int i = 0 ; i < n - 1 ; i++){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        swap(q1 , q2);
        return temp;
       }
    }
    
    int top() {
       if(q1.empty()) return -1;
       else{
        int n = q1.size();
        for(int i = 0 ; i < n - 1 ; i++){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q1.pop();
        swap(q1 , q2);
        q1.push(temp);
        return temp;
       }
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