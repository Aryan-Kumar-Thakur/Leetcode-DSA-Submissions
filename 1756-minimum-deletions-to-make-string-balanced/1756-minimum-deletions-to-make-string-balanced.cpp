class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        int n=s.size();
        int ind=0;
        int cnt=0;
        while(ind<n){
            if(s[ind]=='a'){
                if(!st.empty()){
                    st.pop();
                    cnt++;
                }
            }
            else{
                st.push(s[ind]);
            }
            ind++;
        }
        return cnt;
    }
};