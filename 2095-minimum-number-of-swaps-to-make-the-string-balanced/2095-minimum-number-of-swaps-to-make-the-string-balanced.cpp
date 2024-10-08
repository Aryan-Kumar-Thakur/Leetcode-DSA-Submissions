class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char> st;
        for(auto it:s){
            if(!st.empty() && it==']' && st.top()=='['){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        int x=st.size();
        int ans=x/4;
        if(x%4!=0){
            ans++;
        }
        return ans;
    }
};