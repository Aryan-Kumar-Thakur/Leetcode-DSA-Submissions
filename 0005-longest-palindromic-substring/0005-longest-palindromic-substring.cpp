class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int ind=0;
        int sind=0;
        int maxlen=0;
        while(ind<n){
            int left=ind,right=ind;
            while(left>=0 && s[left]==s[ind]){
                left--;
            }
            while(right<n && s[right]==s[ind]){
                right++;
            }
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1 > maxlen){
                maxlen=right-left-1;
                sind=left+1;
            }
            ind++;
        }
        return s.substr(sind,maxlen);
    }
};