class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string ans1="",ans2="";
        int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#' && !st.empty()){
                st.pop();
            }
            else if(s[i]!='#'){
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans1+=st.top();
            st.pop();
        }
        for(int i=0;i<m;i++){
            if(t[i]=='#' && !st.empty()){
                st.pop();
            }
            else if(t[i]!='#'){
                st.push(t[i]);
            }
        }
        while(!st.empty()){
            ans2+=st.top();
            st.pop();
        }
        return (ans1==ans2);
    }
};