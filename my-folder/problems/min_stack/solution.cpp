class MinStack {
public:
    stack<int> s1, s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.size()) s2.push(min(s2.top(), val));
        else s2.push(val);
    }
    
    void pop() {
        if(s1.size()) s1.pop();
        if(s2.size()) s2.pop();
    }
    
    int top() {
        if(s1.size()) return s1.top();
        return -1;
    }
    
    int getMin() {
        if(s2.size()) return s2.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */