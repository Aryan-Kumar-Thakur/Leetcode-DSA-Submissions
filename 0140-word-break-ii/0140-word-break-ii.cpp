class Solution {
    vector<string> ans;
    void solve(string &s,string output,int ind,int n,set<string> &st){
        if(ind==n){
            ans.push_back(output);
            return;
        }
        for(int i=ind;i<n;i++){
            string k=s.substr(ind,i-ind+1);
            if(st.find(k)!=st.end()){
                if(output.empty()){
                    solve(s,output+k,i+1,n,st);
                }
                else{
                    solve(s,output+" "+k,i+1,n,st);
                }
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it:wordDict){
            st.insert(it);
        }
        string output="";
        int n=s.size();
        solve(s,output,0,n,st);
        return ans;
    }
};