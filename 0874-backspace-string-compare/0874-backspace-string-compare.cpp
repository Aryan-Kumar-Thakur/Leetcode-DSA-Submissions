class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size(),m=t.size();
        int i=n-1,j=m-1;
        int hash1=0,hash2=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    hash1++;
                    i--;
                }
                else if(hash1 > 0){
                    hash1--;
                    i--;
                }
                else{
                    break;
                }
            }
            while(j>=0){
                if(t[j]=='#'){
                    hash2++;
                    j--;
                }
                else if(hash2>0){
                    hash2--;
                    j--;
                }
                else{
                    break;
                }
            }
            char c1= (i < 0)? '$' : s[i];
            char c2= (j < 0)? '$' : t[j];
            if(c1!=c2){
                return false;
            }
            else{
                i--;
                j--;
            }
        }
        return (i<0 && j<0);
    }
};