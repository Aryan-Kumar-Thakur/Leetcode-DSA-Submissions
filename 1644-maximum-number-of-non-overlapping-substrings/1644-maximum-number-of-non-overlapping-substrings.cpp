class Solution {
    int solve(string &s,int i,vector<int> &left,vector<int> &right){
        int r=right[s[i]-'a'];
        for(int j=i;j<=r;j++){
            int l=left[s[j]-'a'];
            if(l<i){
                return -1;
            }
            r=max(r,right[s[j]-'a']);
        }
        return r;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> left(26,INT_MAX);
        vector<int> right(26,INT_MIN);
        for(int i=0;i<n;i++){
            left[s[i]-'a']=min(left[s[i]-'a'],i);
            right[s[i]-'a']=i;
        }
        vector<string> res;
        int r=-1;
        for(int i=0;i<n;i++){
            if(i==left[s[i]-'a']){
                int new_right=solve(s,i,left,right);
                if(new_right!=-1){
                    if(i>r){
                        res.push_back("");
                    }
                    r=new_right;
                    res.back()=s.substr(i,r-i+1);
                }
            }
        }
        return res;
    }
};