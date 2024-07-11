class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it:ans){
                    st.push(it);
                }
                ans="";
            }
            else{
                st.push(s[i]);
            }
        }
        ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};