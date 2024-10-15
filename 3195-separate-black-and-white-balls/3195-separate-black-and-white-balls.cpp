class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long ans=0;
        int i=n-1,j=n-1;
        while(i>=0 && s[i]=='1' && s[j]=='1'){
            i--;
            j--;
        }
        while(i>=0 && j>=0){
            if(s[i]=='1'){
                ans+=(long long)(j-i);
                j--;
            }
            i--;
        }
        return ans;
    }
};