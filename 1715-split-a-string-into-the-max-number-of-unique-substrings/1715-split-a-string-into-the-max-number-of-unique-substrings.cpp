class Solution {
    int solve(int ind,int n,string &s,set<string> &st){
        if(ind==n){
            return 0;
        }
        int ans=0;
        for(int i=ind+1;i<=n;i++){
            string k=s.substr(ind,i-ind);
            if(st.find(k)==st.end()){
                st.insert(k);
                ans=max(ans,1+solve(i,n,s,st));
                st.erase(k);
            }
        }
        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        int n=s.size();
        return solve(0,n,s,st);
    }
};