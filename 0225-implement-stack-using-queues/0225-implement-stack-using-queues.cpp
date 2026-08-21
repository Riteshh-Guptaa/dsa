class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();

        while(n > 1){
            q.push(q.front());
            q.pop();
            n--;
        }
    }
    
    int pop() {
        if(!q.empty()){
            int ans = q.front();
            q.pop();
            return ans;
        }
        return -1;
    }
    
    int top() {
        if(!q.empty()) return q.front();
        return -1;
    }
    
    bool empty() {
        return q.empty();
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