class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=n-1,j=m-1;
        int hash1=0,hash2=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    hash1++;
                    i--;
                }
                else if(hash1>0){
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
            char c1,c2;
            if((i<0 && j>=0) || (j<0 && i>=0)){
                return false;
            }
            else if(i<0 && j<0){
                break;
            }
            else{
            c1=s[i];
            c2=t[j];
            }
            if(c1!=c2){
                return false;
            }
            else{
                i--;
                j--;
            }
        }
        return true;
    }
};