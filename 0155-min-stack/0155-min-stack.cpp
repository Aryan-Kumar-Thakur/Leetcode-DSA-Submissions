class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || val <= minst.top()){
            minst.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()){
            if(!minst.empty() && minst.top()==st.top()){
                minst.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        int ans=0;
        if(!st.empty()){
            ans = st.top();
        }
        return ans;
    }
    
    int getMin() {
        int ans=0;
        if(!minst.empty()){
           ans = minst.top();
        }
        return ans;
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