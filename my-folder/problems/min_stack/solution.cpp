class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    int k = INT_MAX;
    MinStack() {
        minSt.push(k);
        
    }
    
    void push(int val) {
        st.push(val);
        int min_Ele = min(val, minSt.top());
        minSt.push(min_Ele);
    }
    
    void pop() {
        st.pop();
        minSt.pop();        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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