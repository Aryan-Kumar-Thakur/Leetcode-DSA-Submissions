class Solution {
public:
    int myAtoi(string s) {
        bool neg=0;
        long long ans=0;
        int n=s.size();
        int i=0;
        while(s[i]==' ' && i<n){
            i++;
        }
        if(s[i]=='-'){
            neg=1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                if(ans*10+(s[i]-'0') > INT_MAX){
                    if(neg){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                ans=ans*10+(s[i]-'0');
                i++;
            }
            else{
                break;
            }
        }
        if(neg){
            ans=(-1)*ans;
        }
        return ans;
    }
};