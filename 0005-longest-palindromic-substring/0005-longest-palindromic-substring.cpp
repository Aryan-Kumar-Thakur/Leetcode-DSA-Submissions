class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            int l = (i>0) ? i-1 : -1;
            int r = (i<n-1) ? i+1 : n;
            while(l>0 && s[l]==s[i]){
                l--;
            }
            while(r<n && s[r]==s[i]){
                r++;
            }
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
            // cout<<l<<" "<<r<<endl;
            l++;
            r--;
            string x=s.substr(l,(r-l)+1);
            if(x.size()>ans.size()){
                ans=x;
            }
        }
        return ans;
    }
};