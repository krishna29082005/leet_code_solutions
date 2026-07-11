class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    int front;
    int rear;
    MyStack() {
        front = -1;
        rear = -1;
    }
    
    void push(int x) {
       q1.push(x);
    }
    
    int pop() {
       
       int n = q1.size();
       for(int i = 0 ; i < n - 1 ; i++){
           q2.push(q1.front());
           q1.pop();
       }
       int val = q1.front();
       q1.pop();
       swap(q1 , q2);
       return val;
    }
    
    int top() {
        int n = q1.size();
       for(int i = 0 ; i < n - 1 ; i++){
           q2.push(q1.front());
           q1.pop();
       }
       int temp = q1.front();
       q1.pop();
       q2.push(temp);
       swap(q1 , q2);
       return temp;
    }
    
    bool empty() {
       return q1.empty();
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