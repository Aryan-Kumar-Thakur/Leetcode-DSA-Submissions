class MyStack {
    queue<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int n=q1.size();
        int cnt=1;
        while(cnt<n){
            q1.push(q1.front());
            q1.pop();
            cnt++;
        }
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        int ele=q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        if(empty()){
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        return (q1.size()==0);
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