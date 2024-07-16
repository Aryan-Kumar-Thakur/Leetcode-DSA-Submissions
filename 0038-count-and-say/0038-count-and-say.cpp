class Solution {
    string solve(string &str){
        int cnt=1;
        int n=str.size();
        string ans="";
        for(int i=1;i<n;i++){
            if(str[i]==str[i-1]){
                cnt++;
            }
            else{
                ans+=to_string(cnt);
                ans+=str[i-1];
                cnt=1;
            }
        }
        ans+=to_string(cnt);
        ans+=str[n-1];
        return ans;
    }
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=2;i<=n;i++){
            ans=solve(ans);
        }
        return ans;
    }
};