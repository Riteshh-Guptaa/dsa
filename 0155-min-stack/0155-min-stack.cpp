class MinStack {
    stack<int> mn;
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(mn.empty() || mn.top() >= value){
            mn.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(mn.top() == st.top()){
            mn.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */