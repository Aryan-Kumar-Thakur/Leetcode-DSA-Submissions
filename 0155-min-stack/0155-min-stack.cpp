class MinStack {
    stack<int> st1;
    stack<int> st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st1.empty()){
            st1.push(val);
            st2.push(val);
        }
        else{
            if(val <= st2.top()){
                st2.push(val);
            }
            st1.push(val);
        }
    }
    
    void pop() {
        if(st1.top()==st2.top()){
            st2.pop();
        }
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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