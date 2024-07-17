class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(n<m){
            return -1;
        }
        vector<int> lcs(m,0);
        int pre=0,suff=1;
        while(pre<m && suff<m){
            if(needle[pre]==needle[suff]){
                lcs[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lcs[suff]=0;
                    suff++;
                }
                else{
                    pre=lcs[pre-1];
                }
            }
        }
        int i=0,j=0;
        while(i<n && j<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lcs[j-1];
                }
            }
        }
        if(i==n && j<m){
            return -1;
        }
        return (i-m);
    }
};