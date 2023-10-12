class Solution {
    int toint(string &s){
        int i=0;
        bool neg=0;
        if(s[i]=='-'){
            i++;
            neg=1;
        }
        int ans=0;
        while(i<s.size()){
            ans = (ans*10 + (s[i]-'0'));
            i++;
        }
        return (neg)? -ans:ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b+a);
            }
            else if(tokens[i]=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(tokens[i]=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b*a);
            }
            else if(tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }
            else{
                int x=toint(tokens[i]);
                st.push(x);
            }
        }
        return st.top();
    }
};