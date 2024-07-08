class Solution {
    vector<vector<string>> ans;
    bool ispalli(string str){
        string k=str;
        reverse(k.begin(),k.end());
        return (k==str);
    }
    void solve(string &s,int ind,int n,vector<string> out){
        if(ind==n){
            ans.push_back(out);
            return;
        }
        for(int i=ind;i<n;i++){
            string str=s.substr(ind,i-ind+1);
            if(ispalli(str)){
                out.push_back(str);
                solve(s,i+1,n,out);
                out.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> out;
        solve(s,0,n,out);
        return ans;
    }
};