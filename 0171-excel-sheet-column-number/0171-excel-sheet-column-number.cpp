class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char,int> mp;
        int j=1;
        for(char i='A';i<='Z';i++){
            mp[i]=j;
            j++;
        }
        int n=columnTitle.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(pow(26,n-i-1)*mp[columnTitle[i]]);
        }
        return ans;
    }
};