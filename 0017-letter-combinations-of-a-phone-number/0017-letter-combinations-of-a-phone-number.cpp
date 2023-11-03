class Solution {
    void solve(string &digits,vector<string> &ans,string output,map<int,string> &mp,int ind,int n){
        // if(ind>=n){
        //     return;
        // }
        if(output.size()==n){
            ans.push_back(output);
            return;
        }
        int d=digits[ind]-'0';
        for(int i=0;i<mp[d].size();i++){
            output.push_back(mp[d][i]);
            solve(digits,ans,output,mp,ind+1,n);
            output.pop_back();
        }
        // return;
    }
public:
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> ans;
        if(digits==""){
            return ans;
        }
        int n=digits.size();
        solve(digits,ans,"",mp,0,n);
        return ans;
    }
};