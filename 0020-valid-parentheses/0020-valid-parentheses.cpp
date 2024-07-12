class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto it:s){
            if(it==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(it=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(it==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(it);
            }
        }
        return (st.empty());
    }
};