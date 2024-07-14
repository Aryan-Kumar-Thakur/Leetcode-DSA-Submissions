class MinStack {
public:
int mini;
stack<int> st;
    MinStack() {
        mini=0;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else if(val > mini){
            st.push(val);
        }
        else{
            st.push(2*val-mini);
            mini=val;
        }
    }
    
    void pop() {
        int y =st.top();
        if(y>mini){
            st.pop();
        }
        else{
            mini=2*mini-st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
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